/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarodrig <rarodrig@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 18:23:12 by rarodrig          #+#    #+#             */
/*   Updated: 2021/05/21 18:23:12 by rarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	n_c;

	n_c = (unsigned char ) c;
	while (*(unsigned char *) s != n_c)
	{
		if (*(unsigned char *) s == '\0')
		{
			return (NULL);
		}
		++s;
	}
	return ((char *) s);
}
