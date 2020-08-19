/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaneera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 17:07:51 by kmaneera          #+#    #+#             */
/*   Updated: 2020/02/27 20:23:19 by kmaneera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move(t_sto *inf, int key)
{
	t_cn dif;

	dif.ip = inf->max_imag - inf->min_imag;
	dif.rp = inf->max_real - inf->min_real;
	if (key == ARW_UP)
	{
		inf->min_imag += dif.ip * 0.1;
		inf->max_imag += dif.ip * 0.1;
	}
	else if (key == ARW_DOWN)
	{
		inf->min_imag -= dif.ip * 0.1;
		inf->max_imag -= dif.ip * 0.1;
	}
	else if (key == ARW_LEFT)
	{
		inf->min_real -= dif.rp * 0.1;
		inf->max_real -= dif.rp * 0.1;
	}
	else
	{
		inf->min_real += dif.rp * 0.1;
		inf->max_real += dif.rp * 0.1;
	}
	makeart(inf);
}

void	resetscreen(t_sto *inf)
{
	if (inf->typeindex == 2)
		inf->max_iteration = 70;
	else
		inf->max_iteration = 21;
	inf->min_real = -2.0;
	inf->max_real = 2.0;
	inf->min_imag = -2.0;
	inf->max_imag = 2.0;
	makeart(inf);
}

void	iteration_adj_precise(t_sto *inf, int key)
{
	if (key == NP_PLUS)
	{
		inf->max_iteration++;
		makeart(inf);
	}
	else if (key == NP_MINUS && inf->max_iteration > 1)
	{
		inf->max_iteration--;
		makeart(inf);
	}
}

void	iteration_adj(t_sto *inf, int key)
{
	if (inf->max_iteration <= 20 && inf->max_iteration >= 0)
		return (iteration_adj_precise(inf, key));
	if (key == NP_PLUS)
	{
		inf->max_iteration += 10;
		makeart(inf);
	}
	else if (key == NP_MINUS)
	{
		inf->max_iteration -= 10;
		makeart(inf);
	}
}
