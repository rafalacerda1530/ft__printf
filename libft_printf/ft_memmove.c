/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarodrig <rarodrig@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:02:45 by rarodrig          #+#    #+#             */
/*   Updated: 2021/05/18 12:02:45 by rarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	unsigned char	*dst;
	unsigned char	*src;

	dst = (unsigned char *) str1;
	src = (unsigned char *) str2;
	if (src >= dst)
	{
		ft_memcpy(dst, src, n);
	}
	else
	{
		while (n--)
		{
			dst[n] = src[n];
		}
	}
	return (dst);
}
