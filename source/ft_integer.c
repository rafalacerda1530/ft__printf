/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarodrig <rarodrig@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 09:54:56 by rarodrig          #+#    #+#             */
/*   Updated: 2021/07/12 09:54:56 by rarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void ft_printnumber(char *conv, t_printf *content)
{
	content->i = 0;
	if (content->precision > 0)
	{
		while (content->precision-- > 0)
		{	
			write(1, "0", 1);
			content->i++;
			content->iteration++;
		}
	}

	while(conv[content->i] != '\0')
	{
		write(1, &conv[content->i], 1);
		content->i++;
		content->iteration++;
	}
}

void ft_intdot(char *conv, t_printf *content)
{
	int size;
	size = ft_strlen(conv);
	if (content->flag_dot > 0)
	{

		content->width -= size;
		while (content->precision-- > 0 && content->i < size)
		{
			write(1, "0", 1);
			content->i++;
			content->iteration++;
		}
		if (conv[0] == '0')
			return ;
		else
			ft_printnumber(conv, content);
		content->flag_dot = 0;
	}
}

void ft_integer(int ap, t_printf *content)
{
	content->i = 0;
	char *conv;
	conv = ft_itoa(ap);
	if (content->flag_minus)
	{
		if (content->precision > 0)
			ft_printnumber(conv, content);
		while (conv[content->i] != '\0')
			ft_printnumber(conv, content);
		while (content->precision-- > 0 && content->iteration++)
			write(1, " ", 1);
		content->flag_minus = 0;
	}
	else if (content->flag_dot)
		ft_intdot(conv, content);
	else
		ft_printnumber(conv, content);
	free(conv);
}
