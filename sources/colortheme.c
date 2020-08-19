/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colortheme.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaneera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 17:03:45 by kmaneera          #+#    #+#             */
/*   Updated: 2020/02/27 20:17:08 by kmaneera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_color		get_color(int iteration, t_sto *inf)
{
	t_color	color;
	double	t;

	t = (double)iteration / inf->max_iteration;
	color.channel[0] = 0;
	if (inf->colorthemeindex == 3)
		color.channel[1] = (int8_t)(9 * (1 - t) * pow(t, 3) * 255);
	else if (inf->colorthemeindex == 1)
		color.channel[3] = (int8_t)(8.5 * pow((1 - t), 3) * t * 255);
	else if (inf->colorthemeindex == 2)
		color.channel[2] = (int8_t)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	else
	{
		color.channel[1] = (int8_t)(9 * (1 - t) * pow(t, 3) * 255);
		color.channel[2] = (int8_t)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
		color.channel[3] = (int8_t)(8.5 * pow((1 - t), 3) * t * 255);
	}
	return (color);
}
