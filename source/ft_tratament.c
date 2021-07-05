/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tratament.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarodrig <rarodrig@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:25:38 by rarodrig          #+#    #+#             */
/*   Updated: 2021/06/30 16:25:38 by rarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int ft_tratament(const char *fp, va_list ap, int i)
{
	t_printf content;

	i = ft_check(fp, ap, i);
	if (fp[i] == 'c')
	{
		content.letter = va_arg(ap, int);
		write(1, &content.letter, 1);
	}
	else if (fp[i] == 's')
	{
		content.string = va_arg(ap, char *);
		ft_string(content.string);
	}
	else if (fp[i] == 'p')
	{
		content.pointer = va_arg(ap, unsigned long int);
		ft_pointer(content.pointer);
	}
	return i;
}
