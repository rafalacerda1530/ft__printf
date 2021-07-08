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

void ft_char(t_printf *content)
{
	if(content->flag_minus)
	{	
		write(1, &content->letter, 1);
		while (content->width-- > 1)
			write(1, " ", 1);
	}
	if (content->flag_zero)
	{
		while (content->width-- > 1)
			write(1, "0", 1);
		write(1, &content->letter, 1);
	}
	if (content->flag_num)
	{
		while (content->width-- > 1)
			write(1, " ", 1);
		write(1, &content->letter, 1);
	}
	else
	{
		write(1, &content->letter, 1);
	}
}
