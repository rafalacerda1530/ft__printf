/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarodrig <rarodrig@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 21:07:39 by rarodrig          #+#    #+#             */
/*   Updated: 2021/06/04 21:07:39 by rarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	pos(int c)
{
	int	cont;

	cont = 0;
	if (c == 0)
		return (1);
	if (c < 0)
	{
		cont = 1;
		while (c < 0)
		{
			c /= 10;
			cont++;
		}
	}
	while (c > 0)
	{
		c /= 10;
		cont++;
	}
	return (cont);
}

char	*ft_itoa(int n)
{
	char			*newint;
	unsigned int	i;
	unsigned int	new_n;

	if (n < 0)
		new_n = -n;
	else
		new_n = n;
	i = pos(n);
	newint = (char *)malloc(sizeof(char) * i + 1);
	if (newint == NULL)
		return (NULL);
	newint[i] = '\0';
	while (i > 0)
	{
		i--;
		newint[i] = (new_n % 10) + '0';
		new_n /= 10;
	}
	if (n < 0)
		newint[0] = '-';
	return (newint);
}
