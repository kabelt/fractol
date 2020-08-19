/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaneera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 17:11:11 by kmaneera          #+#    #+#             */
/*   Updated: 2020/02/27 20:21:21 by kmaneera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	changecolortheme(t_sto *inf)
{
	inf->colorthemeindex++;
	inf->colorthemeindex %= 4;
	makeart(inf);
}
