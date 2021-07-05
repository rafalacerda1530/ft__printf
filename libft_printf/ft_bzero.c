/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarodrig <rarodrig@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 13:38:48 by rarodrig          #+#    #+#             */
/*   Updated: 2021/05/17 13:38:48 by rarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	unsigned char	*n_str;
	size_t			cont;

	n_str = (unsigned char *) str;
	cont = 0;
	while (cont < n)
	{
		n_str[cont] = '\0';
		cont++;
	}
}
