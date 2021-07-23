/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarodrig <rarodrig@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 12:19:41 by rarodrig          #+#    #+#             */
/*   Updated: 2021/07/07 12:19:41 by rarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_czero(char fp, t_printf *content)
{
	while (content->width-- > 1)
	{
		write(1, "0", 1);
		content->iteration++;
	}
	if (fp == '%')
		write(1, "%", 1);
	else
		write(1, &content->letter, 1);
}

void	ft_charc(char fp, t_printf *content)
{
	if (content->flag_num)
	{
		while (content->width-- > 1)
		{
			write(1, " ", 1);
			content->iteration++;
		}
		if (fp == '%')
			write(1, "%", 1);
		else
			write(1, &content->letter, 1);
	}
	else
	{
		if (fp == '%')
			write(1, "%", 1);
		else
			ft_putchar_fd(content->letter, 1);
	}
}	

void	ft_char(char fp, t_printf *content)
{
	if (content->flag_minus)
	{
		if (fp == '%')
			write(1, "%", 1);
		else
			write(1, &content->letter, 1);
		while (content->width-- > 1)
		{
			content->iteration++;
			write(1, " ", 1);
		}
	}
	else if (content->flag_zero)
		ft_czero(fp, content);
	else
		ft_charc(fp, content);
	content->flag_minus = 0;
}	
