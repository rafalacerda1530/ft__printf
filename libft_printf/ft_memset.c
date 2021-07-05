/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarodrig <rarodrig@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 10:59:29 by rarodrig          #+#    #+#             */
/*   Updated: 2021/05/17 10:59:29 by rarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_memset(void *str, int c, size_t n)
{
	size_t			cont;
	unsigned char	*n_str;

	cont = 0;
	n_str = (unsigned char *) str;
	while (cont < n)
	{
		n_str[cont] = (unsigned char) c;
		cont++;
	}
	return (str);
}
