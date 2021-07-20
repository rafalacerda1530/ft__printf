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
	if (content->sub)
		write(1, "-", 1);
	int	size;
	size = ft_strlen(content->conv);
	content->precision -= size;
	while (content->precision-- > 0)
	{	
		write(1, "0", 1);
		content->iteration++;
	}
	if (content->conv[0] == '0' && content->precision <= 0 && content->flag_minus && content->width == 0)
		content->i++;
	content->sub = 0;
}

void	ft_flag_zero(t_printf *content, int ap)
{
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
	if (content->sub)
	{
		write(1, "-", 1);
		content->sub = 0;
	}
	p_width(content);
	if (content->conv[0] == '0' && content->precision <= 0)
		return ;
	if (content->flag_dot)
			ft_printnumber(content);
	p_int(content);
	content->flag_zero = 0;
}

void	ft_intdot(t_printf *content)
{
	int	size;

	size = ft_strlen(content->conv);
	if (content->sub)
	{
		write(1, "-", 1);
		content->sub = 0;
	}
	if (content->conv[0] == '0' && content->precision <= 0)
		return ;
	content->precision -= size;
	while (content->precision-- > 0)
	{
		write(1, "0", 1);
		content->iteration++;
	}
	p_int(content);
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
	p_int(content);
	content->flag_num = 0;
}

void	ft_integer(int ap, t_printf *content)
{
	content->i = 0;
	ap = check_integer(ap, content);
	if (content->flag_minus)
	{
		if (content->flag_dot)
			ft_printnumber(content);
		p_int(content);
		while (content->width > 0)
			p_width(content);
		content->flag_minus = 0;
	}
	else if (content->flag_num)
		ft_flagnum(content);
	else if (content->flag_zero)
		ft_flag_zero(content, ap);
	else if (content->flag_dot)
		ft_intdot(content);
	else
		p_int(content);
	free(content->conv);
}
