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

void	ft_flagnumb(unsigned int ap, t_printf *content);
void	ft_point(unsigned int ap, t_printf *content);

void	ft_printnum(t_printf *content)
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

void	ft_flag_z(t_printf *content, unsigned int ap)
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
			ft_printnum(content);
	ft_putnbr_base_u(ap, "0123456789", 1, content);
	content->flag_zero = 0;
}

void	ft_point(unsigned int ap, t_printf *content)
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
	ft_putnbr_base_u(ap, "0123456789", 1, content);
	content->flag_dot = 0;
	content->precision = 0;
}

void	ft_flagnumb(unsigned int ap, t_printf *content)
{
	content->flag_zero = 0;
	while (content->width > 0)
	{
		write(1, " ", 1);
		content->width--;
		content->iteration++;
	}
	if (content->flag_dot)
		ft_point(ap, content);
	if (content->flag_dot && content->precision == 0)
		return ;
	ft_putnbr_base_u(ap, "0123456789", 1, content);
	content->flag_num = 0;
}

void	ft_flag_u(char fp, unsigned int ap, t_printf *content)
{
	content->i = 0;
	check_integer(fp, ap, content);
	if (content->flag_minus)
	{
		if (content->flag_dot)
			ft_printnum(content);
		ft_putnbr_base_u(ap, "0123456789", 1, content);
		while (content->width > 0)
			p_width(content);
		content->flag_minus = 0;
	}
	else if (content->flag_num)
		ft_flagnumb(ap, content);
	else if (content->flag_zero)
		ft_flag_z(content, ap);
	else if (content->flag_dot)
		ft_point(ap, content);
	else
		ft_putnbr_base_u(ap, "0123456789", 1, content);
	free(content->conv);
}
