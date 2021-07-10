/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarodrig <rarodrig@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 08:23:49 by rarodrig          #+#    #+#             */
/*   Updated: 2021/07/05 08:23:49 by rarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int ft_getnumber(const char *fp, t_printf *content)
{
	int number;
	content->width = 0;
	number = 0;
	while (ft_isdigit(fp[content->index]))
	{
		number = number * 10 + (fp[content->index] - '0');
		content->index++;
		if(!content->flag_minus && !content->flag_zero)
			content->flag_num = 1;
	}
	content->width = number;
	return(number);
}

void ft_minus(const char *fp, t_printf *content)
{
	
	while (fp[content->index] == '-' || fp[content->index] == '0')
	{
		if (fp[content->index] == '-')
		{
			content->flag_minus = 1;
			content->flag_zero = 0;
		}
		else if (fp[content->index] == '0' && content->flag_minus == 0)
		{
			content->flag_zero = 1;
		}
		content->index++;
	}
}

void ft_dot(const char *fp,  t_printf *content)
{
	int number;

	content->flag_dot = 1;
	content->index++;
	number = 0;
	if (ft_isdigit(fp[content->index]))
	{
		while (ft_isdigit(fp[content->index]))
		{
			number = number * 10 + (fp[content->index] - '0');
			content->index++;
		}
	}
	content->precision = number;
}

void ft_check(const char *fp, t_printf *content)
{
	if(fp[content->index] == '-' || fp[content->index] == '0')
		ft_minus(fp, content);
	ft_getnumber(fp, content);
	if (fp[content->index] == '.')
		ft_dot(fp, content);
}
