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

void 	ft_putnbr_base_fd(unsigned long int num, char *base, int fd, t_printf *content)
{
	size_t len_base;
	len_base = ft_strlen(base);
	content->cont++;
	if (num / len_base > 0)
		ft_putnbr_base_fd(num / len_base, base, fd, content);
	ft_putchar_fd(base[num % len_base], fd);
}

void ft_tratament(const char *fp, va_list ap, t_printf *content)
{
	
	ft_check(fp, content);
	
	if (fp[content->index] == 'c')
	{
		content->letter = va_arg(ap, int);
		ft_char(content);
		content->iteration++;
	}
	else if (fp[content->index] == 's')
	{
		content->string = va_arg(ap, char *);
		ft_string(content->string, content);

	}
	else if (fp[content->index] == 'p')
	{
		content->pointer = va_arg(ap, unsigned long int);
		ft_pointer(content->pointer, content);
	}
}
