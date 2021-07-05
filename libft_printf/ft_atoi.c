/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarodrig <rarodrig@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 20:45:41 by rarodrig          #+#    #+#             */
/*   Updated: 2021/05/22 20:45:41 by rarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	res;
	int	sign;
	int	cont;

	res = 0;
	sign = 1;
	cont = 0;
	while (nptr[cont] == ' ' || (nptr[cont] >= '\t' && nptr[cont] <= '\r' ))
	{
		cont++;
	}
	if (nptr[cont] == '+' || nptr[cont] == '-')
	{
		if (nptr[cont] == '-')
		{
			sign *= -1;
		}
		cont++;
	}
	while (nptr[cont] >= '0' && nptr[cont] <= '9')
	{
		res = nptr[cont] - '0' + (res * 10);
		cont++;
	}
	return (res * sign);
}
