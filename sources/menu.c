/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaneera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 17:29:19 by kmaneera          #+#    #+#             */
/*   Updated: 2020/02/27 20:24:57 by kmaneera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		putmenu2(t_sto *inf)
{
	if (inf->typeindex == 2 && inf->juliamodeindex)
		mlx_string_put(inf->mlx, inf->win, 1060, 1160, 0x00FF00, "JULIA MODE");
	else if (inf->typeindex == 2)
		mlx_string_put(inf->mlx, inf->win, 1060, 1160, 0x404040, "JULIA MODE");
	mlx_string_put(inf->mlx, inf->win, 200, 18, 0x404040, "CONTROLS");
	mlx_string_put(inf->mlx, inf->win, 40, 40, 0x404040,\
			"MOVE                : ARROWS");
	mlx_string_put(inf->mlx, inf->win, 40, 60, 0x404040,\
			"ZOOM                : SCROLL UP/DOWN");
	mlx_string_put(inf->mlx, inf->win, 40, 80, 0x404040,\
			"ALTER MAX_ITERATION : +/- (NUMPAD)");
	mlx_string_put(inf->mlx, inf->win, 40, 100, 0x404040,\
			"CHANGE THEME COLOR  : T");
	mlx_string_put(inf->mlx, inf->win, 40, 120, 0x404040,\
			"RESET               : R");
	if (inf->typeindex == 2)
		mlx_string_put(inf->mlx, inf->win, 40, 140, 0x404040,\
				"ENABLE JULIA MODE   : J");
}

void		putmenu(t_sto *inf)
{
	char *iteration;
	char *ite_num;

	iteration = (char*)ft_memalloc(sizeof(char) * 100);
	ft_strcpy(iteration, "ITERATION : ");
	ft_strcat(iteration, ite_num = ft_itoa(inf->max_iteration));
	if (inf->typeindex == 1)
		mlx_string_put(inf->mlx, inf->win, 1055, 20, 0x404040,\
				"MANDELBROT");
	if (inf->typeindex == 2)
		mlx_string_put(inf->mlx, inf->win, 1090, 20, 0x404040,\
				"JULIA");
	if (inf->typeindex == 3)
		mlx_string_put(inf->mlx, inf->win, 1050, 20, 0x404040,\
				"BURNING SHIP");
	if (inf->typeindex == 4)
		mlx_string_put(inf->mlx, inf->win, 1055, 20, 0x404040,\
				"MANDELBAR");
	mlx_string_put(inf->mlx, inf->win, 20, 1160, 0x404040, iteration);
	putmenu2(inf);
	free(iteration);
	free(ite_num);
}
