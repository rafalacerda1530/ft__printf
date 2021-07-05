/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarodrig <rarodrig@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 12:04:57 by rarodrig          #+#    #+#             */
/*   Updated: 2021/05/19 12:04:57 by rarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*n_str1;
	unsigned char	*n_str2;

	n_str1 = (unsigned char *) str1;
	n_str2 = (unsigned char *) str2;
	while (n > 0)
	{
		if (*n_str1 != *n_str2)
		{
			return (*n_str1 - *n_str2);
		}
		n_str2++;
		n_str1++;
		n--;
	}
	return (0);
}
