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

void	ft_flagnumb(char fp, unsigned int ap, t_printf *content);
void	ft_point(char fp, unsigned int ap, t_printf *content);

void	ft_printnum(unsigned int ap, t_printf *content)
{
	content->cont_u = 0;
	ft_count_digits(ap, "0123456789", content);
	if (ap == 0 && !content->flag_zero)
		content->precision += 1;
	content->precision -= content->cont_u;
	while (content->precision-- > 0)
	{	
		write(1, "0", 1);
		content->iteration++;
	}
	if (content->conv[0] == '0' && content->precision <= 0
		&& content->flag_minus && content->width == 0)
		content->i++;
}

void	ft_flag_z(char fp, t_printf *content, unsigned int ap)
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
	ft_count_digits(ap, "0123456789", content);
	content->width += ft_strlen(content->conv);
	content->width -= content->cont_u;
	p_width(content);
	if (content->conv[0] == '0' && content->precision <= 0)
		return ;
	if (content->flag_dot)
		ft_printnum(ap, content);
	ft_putnbr_u(ap, "0123456789", fp, content);
	content->flag_zero = 0;
}

void	ft_point(char fp, unsigned int ap, t_printf *content)
{
	ft_count_digits(ap, "0123456789", content);
	if (content->conv[0] == '0' && content->precision <= 0)
		return ;
	content->precision -= content->cont_u;
	while (content->precision-- > 0)
	{
		write(1, "0", 1);
		content->iteration++;
	}
	ft_putnbr_u(ap, "0123456789", fp, content);
	content->flag_dot = 0;
	content->precision = 0;
}

void	ft_flagnumb(char fp, unsigned int ap, t_printf *content)
{
	content->flag_zero = 0;
	ft_count_digits(ap, "0123456789", content);
	content->width += ft_strlen(content->conv);
	content->width -= content->cont_u;
	while (content->width > 0)
	{
		write(1, " ", 1);
		content->width--;
		content->iteration++;
	}
	if (content->flag_dot)
		ft_point(fp, ap, content);
	if (content->flag_dot && content->precision == 0)
		return ;
	ft_putnbr_u(ap, "0123456789", fp, content);
	content->flag_num = 0;
}

void	ft_flag_u(char fp, unsigned int ap, t_printf *content)
{
	content->i = 0;
	check_integer(fp, ap, content);
	if (content->flag_minus)
	{
		ft_count_digits(ap, "0123456789", content);
		if (content->flag_dot)
			ft_printnum(ap, content);
		ft_putnbr_u(ap, "0123456789", fp, content);
		content->width += ft_strlen(content->conv);
		content->width -= content->cont_u;
		while (content->width > 0)
			p_width(content);
		content->flag_minus = 0;
		content->cont_u = 0;
	}
	else if (content->flag_num)
		ft_flagnumb(fp, ap, content);
	else if (content->flag_zero)
		ft_flag_z(fp, content, ap);
	else if (content->flag_dot)
		ft_point(fp, ap, content);
	else
		ft_putnbr_u(ap, "0123456789", fp, content);
	free(content->conv);
	content->cont_u = 0;
}
