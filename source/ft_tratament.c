/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tratament.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarodrig <rarodrig@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:25:38 by rarodrig          #+#    #+#             */
/*   Updated: 2021/06/30 16:25:38 by rarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char ft_tratament(const char *fp, va_list ap, int i)
{
	t_printf content;

	if (fp[i + 1] == 'c')
	{
		content.letter = va_arg(ap, int);
		ft_char(content.letter);
	}
	return 0;
}
