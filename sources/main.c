/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaneera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 17:14:05 by kmaneera          #+#    #+#             */
/*   Updated: 2020/02/27 20:21:00 by kmaneera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		print_instr(void)
{
	write(1, "\n", 1);
	ft_putendl("Usage: ./fractol <fractol_name>");
	write(1, "\n", 1);
	ft_putendl("Available fractols:");
	ft_putendl(" - Mandelbrot");
	ft_putendl(" - Julia");
	ft_putendl(" - Burning_ship");
	ft_putendl(" - Mandelbar");
	write(1, "\n", 1);
	exit(1);
	return (1);
}

int		find_fttype(t_sto *inf, char *ft_name)
{
	if (!ft_strcmp(ft_name, "Mandelbrot"))
		inf->typeindex = 1;
	else if (!ft_strcmp(ft_name, "Julia"))
	{
		inf->typeindex = 2;
		inf->j_re = .355;
		inf->j_img = .355;
	}
	else if (!ft_strcmp(ft_name, "Burning_ship"))
		inf->typeindex = 3;
	else if (!ft_strcmp(ft_name, "Mandelbar"))
		inf->typeindex = 4;
	else
		return (print_instr());
	return (0);
}

t_sto	*inf_ini(char *ft_name)
{
	t_sto *inf;

	if (!(inf = (t_sto*)ft_memalloc(sizeof(t_sto))))
		errexit("Error! cannot allocate memory");
	if (!(inf->mlx = mlx_init()))
		errexit("Error! fail to eatablish mlx connection");
	if (!(inf->win = mlx_new_window(inf->mlx, WIDTH, HEIGHT, "FRACTOL")))
		errexit("Error! cannot create a new window");
	if (!(inf->img = mlx_new_image(inf->mlx, WIDTH, HEIGHT)))
		errexit("Error! cannot create a new image");
	inf->img_addr = mlx_get_data_addr(inf->img, &inf->img_bpp,\
			&inf->img_sl, &inf->img_edn);
	find_fttype(inf, ft_name);
	if (inf->typeindex == 2)
		inf->max_iteration = 70;
	else
		inf->max_iteration = 23;
	inf->min_real = -2.0;
	inf->max_real = 2.0;
	inf->min_imag = -2.0;
	inf->max_imag = 2.0;
	return (inf);
}

int		main(int ac, char **av)
{
	t_sto *inf;

	if (ac != 2)
		return (print_instr());
	inf = inf_ini(av[1]);
	makeart(inf);
	control(inf);
	mlx_loop(inf->mlx);
	return (0);
}
