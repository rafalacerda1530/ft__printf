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

int check_integer(int ap, t_printf *content)
{
	if (ap < 0)
	{
		ap *= -1;
		content->sub = 1;
		content->iteration++;
		if ((content->flag_num && content->precision == 0) || (content->flag_minus && content->precision == 0))
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
	return (ap);
}

void p_width(t_printf *content)
{
	while (content->width > 0)
	{
		write(1, " ", 1);
		content->iteration++;
		content->width--;
	}
}
