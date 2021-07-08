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

int ft_printf(const char *fp, ...)
{
	va_list ap;
	t_printf content;
	content.index = 0;

	va_start(ap, fp);  
	while (fp[content.index] != '\0')
	{
		if (fp[content.index] == '%')
		{
			content.index++;
			ft_tratament(fp, ap, &content);
		}
		else
			write(1, &fp[content.index], 1);
		content.index++;
	}
	va_end(ap);
	return 0;
}
