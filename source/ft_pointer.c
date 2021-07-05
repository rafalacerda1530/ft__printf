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

void 	ft_putnbr_base_fd(unsigned long int num, char *base, int fd)
{
	size_t len_base;

	len_base = ft_strlen(base);
	if (num / len_base > 0)
		ft_putnbr_base_fd(num / len_base, base, fd);
	ft_putchar_fd(base[num % len_base], fd);
}

char ft_pointer(unsigned long int fp)
{
	write (1, "0x",2);
	ft_putnbr_base_fd(fp, "0123456789abcdef", 1);
	return 0;
}
