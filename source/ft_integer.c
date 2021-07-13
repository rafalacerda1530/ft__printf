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
		int size;
		size = ft_strlen(conv);
		content->precision -= size;
		while (conv[content->i] != '\0' && content->precision-- > 0)
		{	
			write(1, "0", 1);
			content->i++;
			content->iteration++;
		}
		content->precision = 0;
	}
	else
	{
		while(conv[content->i] != '\0')
		{
			write(1, &conv[content->i], 1);
			content->i++;
			content->iteration++;
		}
	}
}

void ft_intdot(char *conv, t_printf *content)
{
	int size;
	size = ft_strlen(conv);

	if (content->sub)
		write(1, "-", 1);
	if (conv[0] == '0' && content->precision <= 0)
		return ;
	content->precision -= size;
	while (content->precision-- > 0)
	{
		write(1, "0", 1);
		content->i++;
		content->iteration++;
	}
	ft_printnumber(conv, content);
	content->flag_dot = 0;
	content->precision = 0;
}

void ft_integer(int ap, t_printf *content)
{
	char *conv;
	content->i = 0;
	if (ap < 0)
	{
		ap *= -1;
		content->sub = 1;
		content->iteration++;
	}
	conv = ft_itoa(ap);
	if (!conv)
		return ;
	if (!content->flag_dot || content->precision > 0)
	{
		if (content->width && content->precision > 0)
			content->width -= content->precision;
		else
			content->width -= ft_strlen(conv);
	}
	if (content->flag_minus)
	{
		if (content->precision > 0)
			ft_printnumber(conv, content);
		content->i = 0;
		while (conv[content->i] != '\0')
			ft_printnumber(conv, content);
		while (content->width-- > 0 && content->iteration++)
			write(1, " ", 1);
		content->flag_minus = 0;
	}
	else if (content->flag_num)
	{
		content->flag_zero = 0;
		while (content->width > 0 )
		{
			write(1, " ", 1);
			content->width--;
			content->iteration++;
		}
		if (content->flag_dot)
		{
			ft_intdot(conv, content);
		}
		while (conv[content->i] != '\0')
			ft_printnumber(conv, content);
		content->flag_num = 0;
	}
	else if (content->flag_dot)
		ft_intdot(conv, content);
	else
		ft_printnumber(conv, content);
	free(conv);
}
