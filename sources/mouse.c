/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaneera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 20:17:18 by kmaneera          #+#    #+#             */
/*   Updated: 2020/02/27 20:29:42 by kmaneera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		zoom_mouse(t_sto *inf, int button, int y, int x)
{
	t_cn mouse;

	mouse.rp = inf->min_real + (x / (WIDTH / (inf->max_real - inf->min_real)));
	mouse.ip = inf->max_imag - (y / (HEIGHT / (inf->max_imag - inf->min_imag)));
	if (button == 4)
	{
		if (inf->max_iteration > 20)
			inf->max_iteration -= 2;
		inf->zoom = 0.9;
	}
	else
	{
		inf->zoom = 1.1;
		inf->max_iteration += 2;
	}
	inf->min_real = mouse.rp + (inf->min_real - mouse.rp) * 1 / inf->zoom;
	inf->min_imag = mouse.ip + (inf->min_imag - mouse.ip) * 1 / inf->zoom;
	inf->max_real = mouse.rp + (inf->max_real - mouse.rp) * 1 / inf->zoom;
	inf->max_imag = mouse.ip + (inf->max_imag - mouse.ip) * 1 / inf->zoom;
	makeart(inf);
}

int			mouse(int button, int x, int y, t_sto *inf)
{
	inf->firstline = 0;
	if (button == 4 || button == 5)
		zoom_mouse(inf, button, y, x);
	return (0);
}
