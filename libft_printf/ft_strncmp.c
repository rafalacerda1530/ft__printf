/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarodrig <rarodrig@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 20:23:53 by rarodrig          #+#    #+#             */
/*   Updated: 2021/05/22 20:23:53 by rarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			cont;
	unsigned char	*n_s1;
	unsigned char	*n_s2;

	n_s1 = (unsigned char *) s1;
	n_s2 = (unsigned char *) s2;
	cont = 0;
	while ((n_s1[cont] != '\0' || n_s2[cont] != '\0') && cont < n)
	{
		if (n_s1[cont] != n_s2[cont])
		{
			return (n_s1[cont] - n_s2[cont]);
		}
		cont++;
	}
	return (0);
}
