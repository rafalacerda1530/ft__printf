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

void	ft_flagnum(t_printf *content);
void	ft_intdot(t_printf *content);

void	ft_printnumber(t_printf *content)
{
	content->i = 0;
	if (content->precision > 0)
	{
		int	size;
		size = ft_strlen(content->conv);
		content->precision -= size;
		while (content->precision-- > 0)
		{	
			write(1, "0", 1);
			content->i++;
			content->iteration++;
		}
		content->i = 0;
	}
	else
	{
		if (content->sub)
			write(1, "-", 1);
		while (content->conv[content->i] != '\0')
		{
			write(1, &content->conv[content->i], 1);
			content->i++;
			content->iteration++;
		}
	}
}

void	ft_flag_zero(t_printf *content, int ap)
{
	if (content->sub && content->precision <= 0)
		content->width -= 1;
	if (ap == 0 && content->flag_dot == 0)
	{
		write(1, "0", 1);
		content->iteration++;
		while (content->width > 0)
		{
			write(1, "0", 1);
			content->iteration++;
			content->width--;
		}
	}
	p_width(content);
	if (content->sub)
		write(1, "-", 1);
	if (content->conv[0] == '0' && content->precision <= 0)
		content->i++;
	if (content->flag_dot)
		while (content->conv[content->i] != '\0')
			ft_printnumber(content);
	while (content->conv[content->i] != '\0')
		ft_printnumber(content);
	content->flag_zero = 0;
}

void	ft_intdot(t_printf *content)
{
	int	size;

	size = ft_strlen(content->conv);
	if (content->sub)
		write(1, "-", 1);
	if (content->conv[0] == '0' && content->precision <= 0)
		return ;
	content->precision -= size;
	while (content->precision-- > 0)
	{
		write(1, "0", 1);
		content->i++;
		content->iteration++;
	}
	ft_printnumber(content);
	content->flag_dot = 0;
	content->precision = 0;
}

void	ft_flagnum(t_printf *content)
{
	content->flag_zero = 0;
	while (content->width > 0)
	{
		write(1, " ", 1);
		content->width--;
		content->iteration++;
	}
	if (content->flag_dot)
		ft_intdot(content);
	if (content->flag_dot && content->precision == 0)
		return ;
	while (content->conv[content->i] != '\0')
		ft_printnumber(content);
	content->flag_num = 0;
}

void	ft_integer(int ap, t_printf *content)
{
	content->i = 0;
	ap = check_integer(ap, content);
	if (content->flag_minus)
	{
		if (content->sub)
			write(1, "-", 1);
		if (content->precision > 0)
			ft_printnumber(content);
		content->i = 0;
		while (content->conv[content->i] != '\0')
			ft_printnumber(content);
		while (content->width-- > 0 && content->iteration++)
			write(1, " ", 1);
		content->flag_minus = 0;
	}
	else if (content->flag_num)
		ft_flagnum(content);
	else if (content->flag_zero)
		ft_flag_zero(content, ap);
	else if (content->flag_dot)
		ft_intdot(content);
	else
		ft_printnumber(content);
	free(content->conv);
}
