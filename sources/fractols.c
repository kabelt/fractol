/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaneera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 20:13:36 by kmaneera          #+#    #+#             */
/*   Updated: 2020/02/27 20:36:43 by kmaneera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mandelbrot(t_sto *inf)
{
	int		i;
	t_cn	z;

	i = 0;
	z.ip = inf->cur.ip;
	z.rp = inf->cur.rp;
	while (z.ip * z.ip + z.rp * z.rp <= 4 && i < inf->max_iteration)
	{
		z = make_cn((z.rp * z.rp) - (z.ip * z.ip) + inf->cur.rp,\
				2 * z.rp * z.ip + inf->cur.ip);
		i++;
	}
	return (i);
}

int		burningship(t_sto *inf)
{
	int		i;
	t_cn	z;

	i = 0;
	z.ip = inf->cur.ip;
	z.rp = inf->cur.rp;
	while ((z.ip * z.ip) + (z.rp * z.rp) <= 4 && i < inf->max_iteration)
	{
		z = make_cn((fabs(z.rp) * fabs(z.rp)) - (fabs(z.ip) * fabs(z.ip))\
				- inf->cur.rp, 2 * fabs(z.rp) * fabs(z.ip) - inf->cur.ip);
		i++;
	}
	return (i);
}

int		julia(t_sto *inf)
{
	int		i;
	t_cn	z;

	i = 0;
	z.ip = inf->cur.ip;
	z.rp = inf->cur.rp;
	while ((z.ip * z.ip) + (z.rp * z.rp) <= 4 && i < inf->max_iteration)
	{
		z = make_cn((z.rp * z.rp) - (z.ip * z.ip) + inf->j_re,\
				2 * z.rp * z.ip + inf->j_img);
		i++;
	}
	return (i);
}

int		mandelbar(t_sto *inf)
{
	int		i;
	t_cn	z;

	i = 0;
	z.ip = inf->cur.ip;
	z.rp = inf->cur.rp;
	while ((z.ip * z.ip) + (z.rp * z.rp) <= 4 && i < inf->max_iteration)
	{
		z = make_cn((z.ip * z.ip) - (z.rp * z.rp) + inf->cur.rp,\
				2 * z.rp * z.ip + inf->cur.ip);
		i++;
	}
	return (i);
}

int		fractols(t_sto *inf)
{
	if (inf->typeindex == MANDELBROT)
		return (mandelbrot(inf));
	else if (inf->typeindex == JULIA)
		return (julia(inf));
	else if (inf->typeindex == BURNINGSHIP)
		return (burningship(inf));
	else
		return (mandelbar(inf));
}
