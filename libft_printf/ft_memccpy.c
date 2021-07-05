/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarodrig <rarodrig@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 10:38:45 by rarodrig          #+#    #+#             */
/*   Updated: 2021/05/18 10:38:45 by rarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			cont;
	unsigned char	*n_src;
	unsigned char	*n_dest;

	if (!dest && !src)
		return (NULL);
	n_src = (unsigned char *) src;
	n_dest = (unsigned char *) dest;
	cont = 0;
	while (cont < n)
	{
		if (n_src[cont] == c)
		{
			n_dest[cont] = n_src[cont];
			return (n_dest + cont + 1);
		}
		n_dest[cont] = n_src[cont];
		cont++;
	}
	return (NULL);
}
