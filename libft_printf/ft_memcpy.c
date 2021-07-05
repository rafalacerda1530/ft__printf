/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarodrig <rarodrig@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 10:20:11 by rarodrig          #+#    #+#             */
/*   Updated: 2021/05/18 10:20:11 by rarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
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
		n_dest[cont] = n_src[cont];
		cont++;
	}
	return (n_dest);
}
