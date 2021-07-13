/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarodrig <rarodrig@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 18:56:23 by rarodrig          #+#    #+#             */
/*   Updated: 2021/06/23 18:56:23 by rarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_printf *initialize(t_printf *content)
{
	content->letter = 0;
	content->string = 0;
	content->pointer = 0;
	content->width = 0;
	content->flag_minus = 0;
	content->flag_zero = 0;
	content->index = 0;
	content->flag_num = 0;
	content->cont = 2;
	content->i = 0;
	content->flag_dot = 0;
	content->precision = 0;
	content->iteration = 0;
	content->sub = 0;
	return (content);
}

int ft_printf(const char *fp, ...)
{
	va_list ap;
	t_printf content;
	content.index = 0;

	initialize(&content);
	va_start(ap, fp);  
	content.iteration = 0;
	while (fp[content.index] != '\0')
	{
		if (fp[content.index] == '%')
		{
			content.index++;
			ft_tratament(fp, ap, &content);
			
		}
		else
			content.iteration +=  write(1, &fp[content.index], 1);
		content.index++;
	}
	va_end(ap);
	return content.iteration;
}

