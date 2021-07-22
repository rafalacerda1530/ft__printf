/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarodrig <rarodrig@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 19:42:35 by rarodrig          #+#    #+#             */
/*   Updated: 2021/07/21 19:42:35 by rarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_flagn(char fp, unsigned int ap, t_printf *content);
void	ft_p(char fp, unsigned int ap, t_printf *content);

void	ft_printn(t_printf *content)
{
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
}

void	ft_flag_ze(char fp, t_printf *content, unsigned int ap)
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
	ft_count_digits(ap, "0123456789abcdef", content);
	content->width += ft_strlen(content->conv);
	content->width -= content->cont_u;
	p_width(content);
	if (content->conv[0] == '0' && content->precision <= 0)
		return ;
	if (content->flag_dot)
			ft_printn(content);
	ft_putnbr_base_u(ap, "0123456789abcdef", 1, fp, content);
	content->flag_zero = 0;
}

void	ft_p(char fp, unsigned int ap, t_printf *content)
{
	ft_count_digits(ap, "0123456789abcdef", content);
	if (content->conv[0] == '0' && content->precision <= 0)
		return ;
	content->precision -= content->cont_u;
	while (content->precision-- > 0)
	{
		write(1, "0", 1);
		content->iteration++;
	}
	ft_putnbr_base_u(ap, "0123456789abcdef", 1, fp, content);
	content->flag_dot = 0;
	content->precision = 0;
}

void	ft_flagn(char fp, unsigned int ap, t_printf *content)
{
	content->flag_zero = 0;
	while (content->width > 0)
	{
		write(1, " ", 1);
		content->width--;
		content->iteration++;
	}
	if (content->flag_dot)
		ft_p(fp, ap, content);
	if (content->flag_dot && content->precision == 0)
		return ;
	ft_putnbr_base_u(ap, "0123456789abcdef", 1, fp, content);
	content->flag_num = 0;
}

void	ft_flag_x(char fp, unsigned int ap, t_printf *content)
{
	content->i = 0;
	check_integer(fp, ap, content);
	if (content->flag_minus)
	{
		ft_count_digits(ap, "0123456789abcdef", content);
		if (content->flag_dot)
			ft_printn(content);
		ft_putnbr_base_u(ap, "0123456789abcdef", 1, fp, content);
		content->width += ft_strlen(content->conv);
		content->width -= content->cont_u;
		while (content->width > 0)
			p_width(content);
		content->flag_minus = 0;
		content->cont_u = 0;
	}
	else if (content->flag_num)
		ft_flagn(fp, ap, content);
	else if (content->flag_zero)
		ft_flag_ze(fp, content, ap);
	else if (content->flag_dot)
		ft_p(fp, ap, content);
	else
		ft_putnbr_base_u(ap, "0123456789abcdef", 1, fp, content);
	free(content->conv);
	content->cont_u = 0;
}
