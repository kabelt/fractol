/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_return_nc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaneera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 20:41:15 by kmaneera          #+#    #+#             */
/*   Updated: 2020/01/16 18:15:04 by kmaneera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_putstr_return_nc(char const *s)
{
	int	n[3];

	n[0] = 0;
	n[1] = 0;
	n[2] = 0;
	if (!*s)
	{
		write(1, &n[1], 1);
		n[2] = 1;
		n[0]++;
		s++;
	}
	if (!*(s))
		return (1);
	while (*s)
	{
		write(1, &(*(s++)), 1);
		n[0]++;
	}
	if (n[2] == 0)
	{
		write(1, &n[1], 1);
		n[0] += 1;
	}
	return (n[0]);
}
