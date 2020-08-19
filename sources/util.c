/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaneera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 20:20:08 by kmaneera          #+#    #+#             */
/*   Updated: 2020/02/27 20:20:33 by kmaneera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	errexit(char *str)
{
	write(1, "\e[91m", 5);
	ft_putendl(str);
	exit(1);
}

t_cn	make_cn(double real, double imaginary)
{
	t_cn cn;

	cn.rp = real;
	cn.ip = imaginary;
	return (cn);
}
