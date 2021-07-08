/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarodrig <rarodrig@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 19:32:19 by rarodrig          #+#    #+#             */
/*   Updated: 2021/07/01 19:32:19 by rarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void ft_strdot(char *ap, t_printf *content)
{
	int i;
	int size;

	size = ft_strlen(ap);
	i = 0;
	if (content->flag_dot)
	{
		while (content->precision-- > 0 && i < size )
		{
			write(1, &ap[i], 1);
			i++;
		}
		content->flag_dot = 0;
	}
	else if (content->flag_zero)
	{
		while (content->width-- > 0)
			write(1, " ", 1);
		while (ap[content->i] != '\0')
		{
			write(1, &ap[content->i], 1);
			content->i++;
		}
		content->flag_zero = 0;
	}
}

void	ft_numstr(char *ap, t_printf *content)
{
	int	i;

	i = 0;
	content->flag_zero = 0;
	if (content->flag_num)
	{
		while (content->width-- > 0)
			write(1, " ", 1);
		while (ap[i] != '\0')
		{
			write(1, &ap[i], 1);
			i++;
		}
		content->flag_num = 0;
	}
	else
	{
		while (ap[i] != '\0')
		{
			write(1, &ap[i], 1);
			i++;
		}
	}
}

void	ft_string(char *ap, t_printf *content)
{
	content->i = 0;
	content->width -= ft_strlen((const char *)ap);
	if (content->flag_minus)
	{
		while (ap[content->i] != '\0')
		{
			write(1, &ap[content->i], 1);
			content->i++;
		}
		while (content->width-- > 0)
			write(1, " ", 1);
		content->flag_minus = 0;
	}
	else if (content->flag_dot)
		ft_strdot(ap, content);
	else if (content->flag_zero)
		ft_strdot(ap, content);
	else
		ft_numstr(ap, content);
}