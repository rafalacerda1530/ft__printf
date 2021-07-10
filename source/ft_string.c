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
		while (ap[content->i] != '\0')
			ft_printchar(ap, content);
		content->flag_zero = 0;
	}
}

void	ft_numstr(char *ap, t_printf *content)
{
	content->flag_zero = 0;
	if (content->flag_num)
	{
		while (content->width-- > 0 && content->iteration++)
			write(1, " ", 1);
		if (content->flag_dot)
		{
			ft_strdot(ap, content);
			return ;
		}
		while (ap[content->i] != '\0')
			ft_printchar(ap, content);
		content->flag_num = 0;
	}
	else
	{
		while (ap[content->i] != '\0')
			ft_printchar(ap, content);
	}
}

void	ft_string(char *ap, t_printf *content)
{
	content->i = 0;
	if (!content->flag_dot || content->precision > 0)
	{
		if (content->width && content->precision > 0)
			content->width -= content->precision;
		else
			content->width -= ft_strlen((const char *)ap);
	}
	if (content->flag_minus)
	{
		if (content->precision > 0)
			ft_printchar(ap, content);
		else
			while (ap[content->i] != '\0')
				ft_printchar(ap, content);
		while (content->width-- > 0 && content->iteration++)
			write(1, " ", 1);
		content->flag_minus = 0;
	}
	else if (content->flag_num)
		ft_numstr(ap, content);
	else if (content->flag_zero || content->flag_dot)
		ft_strdot(ap, content);
	else
		ft_numstr(ap, content);
}
