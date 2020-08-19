/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   art.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaneera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 17:19:37 by kmaneera          #+#    #+#             */
/*   Updated: 2020/02/27 20:32:05 by kmaneera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	put_pixel(t_sto *inf, int x, int y, t_color color)
{
	int	i;

	i = (x * inf->img_bpp / 8) + (y * inf->img_sl);
	inf->img_addr[i] = color.channel[3];
	inf->img_addr[++i] = color.channel[2];
	inf->img_addr[++i] = color.channel[1];
	inf->img_addr[++i] = color.channel[0];
}

void		drawslice(t_sto *inf)
{
	int			y;
	int			x;
	t_color		color;

	inf->factor = make_cn((inf->max_real - inf->min_real) / (WIDTH),\
			(inf->max_imag - inf->min_imag) / (HEIGHT));
	y = inf->firstline;
	while (y < inf->lastline)
	{
		inf->cur.ip = inf->max_imag - y * inf->factor.ip;
		x = 0;
		while (x < WIDTH)
		{
			inf->cur.rp = inf->min_real + x * inf->factor.rp;
			color = get_color(fractols(inf), inf);
			put_pixel(inf, x, y, color);
			x++;
		}
		y++;
	}
}

void		makeart(t_sto *inf)
{
	pthread_t	threads[THREADS];
	t_sto		inf_eachslice[THREADS];
	int			i;

	i = 0;
	while (i < THREADS)
	{
		inf_eachslice[i] = *inf;
		inf_eachslice[i].firstline = i * HEIGHT / THREADS;
		inf_eachslice[i].lastline = (i + 1) * (HEIGHT / THREADS);
		if (pthread_create(&threads[i], NULL, (void*)drawslice,\
					(void*)&inf_eachslice[i]))
			errexit("Error! there's a problem with multi-threading");
		i++;
	}
	i = 0;
	while (i < THREADS)
	{
		if (pthread_join(threads[i], NULL))
			errexit("Error! there's a problem with multi-threading");
		i++;
	}
	mlx_put_image_to_window(inf->mlx, inf->win, inf->img, 0, 0);
	putmenu(inf);
}
