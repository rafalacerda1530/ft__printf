/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarodrig <rarodrig@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 15:36:29 by rarodrig          #+#    #+#             */
/*   Updated: 2021/07/02 15:36:29 by rarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void 	ft_count_digits(unsigned long int num, char *base, int fd, t_printf *content)
{
	size_t len_base;
	len_base = ft_strlen(base);
	content->cont++;
	if (num / len_base > 0)
		ft_count_digits(num / len_base, base, fd, content);
}

void 	ft_putnbr_base_fd(unsigned long int num, char *base, int fd, t_printf *content)
{
	size_t len_base;
	len_base = ft_strlen(base);
	content->cont++;
	if (num / len_base > 0)
		ft_putnbr_base_fd(num / len_base, base, fd, content);
	ft_putchar_fd(base[num % len_base], fd);
}

void ft_num(unsigned long int fp, t_printf *content)
{
	ft_count_digits(fp, "0123456789abcdef", 1, content);
	content->width -= content->cont;
	while (content->width-- > 0)
		write(1, " ", 1);
	write (1, "0x",2);
	ft_putnbr_base_fd(fp, "0123456789abcdef", 1, content);
	content->flag_num = 0;
}

void ft_pointer(unsigned long int fp, t_printf *content)
{
	content->cont = 2;

	if(content->flag_minus)
	{
		write (1, "0x",2);
		ft_putnbr_base_fd(fp, "0123456789abcdef", 1, content);
		content->width -= content->cont;
		while (content->width-- > 0)
			write(1, " ", 1);
	}
	else if(content->flag_zero)
	{
		write (1, "0x",2);
		ft_count_digits(fp, "0123456789abcdef", 1, content);
		content->width -=  content->cont;
		while (content->width-- > 0)
			write(1, "0", 1);
		ft_putnbr_base_fd(fp, "0123456789abcdef", 1, content);
	}
	else if(content->flag_num)
	{
		ft_num(fp, content);
	}
	else
	{
		write (1, "0x",2);
		ft_putnbr_base_fd(fp, "0123456789abcdef", 1, content);
	}
}
