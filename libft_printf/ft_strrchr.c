/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarodrig <rarodrig@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 18:48:12 by rarodrig          #+#    #+#             */
/*   Updated: 2021/05/21 18:48:12 by rarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		a;
	char	*n_s;

	n_s = (char *) s;
	i = 0;
	a = -1;
	while (n_s[i])
	{
		if (n_s[i] == (char)c)
			a = i;
		i++;
	}
	if ((char )c == '\0')
		return (n_s + i);
	else if (a >= 0)
		return (n_s + a);
	return (NULL);
}
