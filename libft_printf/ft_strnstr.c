/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarodrig <rarodrig@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 20:03:03 by rarodrig          #+#    #+#             */
/*   Updated: 2021/05/21 20:03:03 by rarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *to_find, size_t len)
{
	size_t	cont1;
	size_t	cont2;

	cont1 = 0;
	cont2 = 0;
	if (*to_find == '\0')
	{
		return ((char *) big);
	}
	while (cont1 < len && big[cont1])
	{
		while (big[cont1 + cont2] == to_find[cont2] && cont1 + cont2 < len
			&& to_find[cont2] != '\0')
		{
			cont2++;
		}
		if (to_find[cont2] == '\0')
		{
			return ((char *) big + cont1);
		}
		cont1++;
		cont2 = 0;
	}
	return (NULL);
}
