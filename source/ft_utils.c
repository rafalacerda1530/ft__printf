/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarodrig <rarodrig@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 10:32:33 by rarodrig          #+#    #+#             */
/*   Updated: 2021/07/15 10:32:33 by rarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int check_integer(char fp, int ap, t_printf *content)
{
	if (ap == 0 || ap == 0)
		content->sub = 0;
	else if(ap < 0 && fp != 'u')
	{
		ap *= -1;
		content->sub = 1;
		content->iteration++;
		if ((content->flag_num && content->precision == 0 && content->flag_dot) && (content->flag_minus && content->precision == 0))
			content->width -= 2;
		else
			content->width -= 1;
	}
	content->conv = ft_itoa(ap);
	if (!content->flag_dot || content->precision > 0)
	{
		if (content->width && content->precision > 0)
			content->width -= content->precision;
		else
			content->width -= ft_strlen(content->conv);
	}
	if (content->conv[0] == '0' && content->precision <= 0 && content->flag_dot)
		content->i++;
	return (ap);
}

void p_width(t_printf *content)
{
	content->i = 0;
	if (content->flag_zero && !content->flag_dot)
	{
		while (content->width > 0)
		{
		write(1, "0", 1);
		content->iteration++;
		content->width--;
		}
	}
	else
	{
		while (content->width > 0)
		{
			write(1, " ", 1);
			content->iteration++;
			content->width--;
		}
	}
}

void p_int(t_printf *content)
{
	if (content->sub)
		write(1, "-", 1);
	if (content->i == 0)
	{
		while (content->conv[content->i] != '\0')
		{
			write(1, &content->conv[content->i], 1);
			content->i++;
			content->iteration++;
		}
	}
	if (content->sub)
		content->sub = 0;
}

void 	ft_putnbr_base_u(unsigned int num, char *base, int fd, t_printf *content)
{
	size_t len_base;
	len_base = ft_strlen(base);
	content->iteration++;
	if (num / len_base > 0)
		ft_putnbr_base_u(num / len_base, base, fd, content);
	ft_putchar_fd(base[num % len_base], fd);
}
