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

void	ft_printchar(char *ap, t_printf *content)
{	
	if (content->precision > 0)
	{
		while (ap[content->i] != '\0' && content->precision-- > 0)
		{
			write(1, &ap[content->i], 1);
			content->i++;
			content->iteration++;
		}
		content->flag_dot = 0;
		content->precision = 0;
	}
	else
	{
		while (ap[content->i] != '\0')
		{
			write(1, &ap[content->i], 1);
			content->i++;
			content->iteration++;
		}
	}
}

void	ft_strdot(char *ap, t_printf *content)
{
	int	size;

	size = ft_strlen(ap);
	if (content->flag_dot)
	{
		content->width -= ft_strlen((const char *)ap);
		while (content->precision-- > 0 && content->i < size)
		{
			write(1, &ap[content->i], 1);
			content->i++;
			content->iteration++;
		}
		content->flag_dot = 0;
	}
	else if (content->flag_zero)
	{
		while (content->width-- > 0)
			write(1, " ", 1);
		ft_printchar(ap, content);
		content->flag_zero = 0;
	}
}

void	ft_numstr(char *ap, t_printf *content)
{
	content->flag_zero = 0;
	if (content->flag_num)
	{
		while (content->width > 0)
		{
			write(1, " ", 1);
			content->iteration++;
			content->width--;
		}
		if (content->flag_dot)
		{
			ft_strdot(ap, content);
			return ;
		}
		ft_printchar(ap, content);
		content->flag_num = 0;
	}
	else
		ft_printchar(ap, content);
}

void	ft_string(char *ap, t_printf *content)
{
	ft_checkstring(ap, content);
	if (content->flag_minus)
	{
		if (content->precision > 0 && ap != NULL)
			ft_printchar(ap, content);
		else if (ap != NULL && content->precision <= 0 && content->width != 0)
			ft_printchar(ap, content);
		while (content->width > 0)
			p_width(content);
		content->flag_minus = 0;
	}
	else if (content->flag_num)
		ft_numstr(ap, content);
	else if (content->flag_zero || content->flag_dot)
		ft_strdot(ap, content);
	else
		ft_numstr(ap, content);
	content->i = 0;
	content->precision = 0;
}
