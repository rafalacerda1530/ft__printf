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

void	ft_trat(const char *fp, va_list ap, t_printf *content)
{
	if (fp[content->index] == 'u')
	{
		content->u = va_arg(ap, unsigned int);
		ft_flag_u(fp[content->index], content->u, content);
	}
	else if (fp[content->index] == 'x' || fp[content->index] == 'X')
	{
		content->x = va_arg(ap, unsigned int);
		ft_flag_x(fp[content->index], content->x, content);
	}
	else if (fp[content->index] == '%')
	{
		content->letter = va_arg(ap, int);
		ft_char(fp[content->index], content);
		content->iteration++;
	}
}

void	ft_putnbr_x(unsigned int num, char *base, char cv, t_printf *content)
{
	size_t	len_base;

	if (content->flag_minus && content->width == 0
		&& content->flag_dot && content->x == 0)
		return ;
	else if (content->flag_minus && content->width && content->flag_dot
		&& content->x == 0)
		return ;
	if (cv == 'X')
		base = "0123456789ABCDEF";
	len_base = ft_strlen(base);
	content->iteration++;
	if (num / len_base > 0)
		ft_putnbr_u(num / len_base, base, cv, content);
	ft_putchar_fd(base[num % len_base], 1);
}

void	ft_putnbr(unsigned long int num, char *base, int fd, t_printf *content)
{
	size_t	len_base;

	len_base = ft_strlen(base);
	content->cont++;
	content->iteration++;
	if (num / len_base > 0)
		ft_putnbr(num / len_base, base, 1, content);
	ft_putchar_fd(base[num % len_base], fd);
}

void	ft_tratament(const char *fp, va_list ap, t_printf *content)
{
	ft_check(fp, content);
	if (fp[content->index] == 'c')
	{
		content->letter = va_arg(ap, int);
		ft_char(fp[content->index], content);
		content->iteration++;
	}
	else if (fp[content->index] == 's')
	{
		content->string = va_arg(ap, char *);
		if (!content->string)
			content->string = "(null)";
		ft_string(content->string, content);
	}
	else if (fp[content->index] == 'p')
	{
		content->pointer = va_arg(ap, unsigned long int);
		ft_pointer(content->pointer, content);
	}
	else if (fp[content->index] == 'd' || fp[content->index] == 'i')
	{
		ft_integer(fp[content->index], va_arg(ap, int), content);
	}
	else
		ft_trat(fp, ap, content);
}
