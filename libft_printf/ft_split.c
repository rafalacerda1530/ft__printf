/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarodrig <rarodrig@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 18:34:29 by rarodrig          #+#    #+#             */
/*   Updated: 2021/06/03 18:34:29 by rarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cword(char const *s, char c)
{
	int	i;
	int	count;
	int	w;

	w = 0;
	i = 0;
	count = 0;
	while (s[i])
	{	
		if (s[i] == c)
			w = 0;
		else if (s[i] != c && w == 0)
		{
			w = 1;
			count++;
		}
		i++;
	}
	return (count);
}

static char	*wordal(char const *s, char c)
{
	char	*str;
	int		size;
	int		cont;

	size = 0;
	while (s[size] && s[size] != c)
		size++;
	str = (char *)malloc(size + 1);
	if (str == NULL)
		return (NULL);
	cont = 0;
	while (cont < size)
	{
		str[cont] = s[cont];
		cont++;
	}
	str[cont] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		i;
	int		f;
	int		w;

	array = (char **)malloc((cword(s, c) + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	i = -1;
	f = -1;
	w = 0;
	while (s[++i])
	{
		if (s[i] == c)
			w = 0;
		else if (s[i] != c && w == 0)
		{
			w = 1;
			array[++f] = wordal(s + i, c);
			if (array[f] == NULL)
				return (NULL);
		}
	}
	array[cword(s, c)] = 0;
	return (array);
}
