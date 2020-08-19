/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaneera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 17:22:39 by kmaneera          #+#    #+#             */
/*   Updated: 2020/02/27 20:32:53 by kmaneera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		julia_activator(t_sto *inf)
{
	if (inf->juliamodeindex == 0)
		inf->juliamodeindex = 1;
	else
		inf->juliamodeindex = 0;
	makeart(inf);
}

static int	keyboard2(int key, t_sto *inf)
{
	if (key == NP_PLUS || key == NP_MINUS)
		iteration_adj(inf, key);
	else if (key == MP_R)
		resetscreen(inf);
	else if (key == MP_J)
		julia_activator(inf);
	else if (key == MP_T)
		changecolortheme(inf);
	return (0);
}

static int	keyboard(int key, t_sto *inf)
{
	if (key == MP_ESC)
		exit(1);
	else if (key >= 123 && key <= 126)
		move(inf, key);
	return (keyboard2(key, inf));
}

int			mouse_move(int x, int y, t_sto *inf)
{
	if (x > 0 && x < 1200 && y > 0 && y < 1200 &&\
			inf->typeindex == JULIA && inf->juliamodeindex)
	{
		inf->j_re = (double)-2 + ((double)x *\
				((double)4 / (double)(WIDTH - 1)));
		inf->j_img = (double)2 - ((double)y *\
				((double)4 / (double)(HEIGHT - 1)));
		makeart(inf);
	}
	return (0);
}

void		control(t_sto *inf)
{
	mlx_hook(inf->win, 6, 0, mouse_move, inf);
	mlx_key_hook(inf->win, keyboard, inf);
	mlx_mouse_hook(inf->win, mouse, inf);
}
