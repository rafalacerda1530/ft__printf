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

int ft_check(const char *fp, va_list ap, int i)
{
	int teste;
	if (fp[i] == '-')
	{
		teste = ft_atoi(&fp[i + 1]);
		while ((fp[i] != 'c') && (fp[i] != 's') && (fp[i] != 'c'))
		{
			i++;		
		}
	}
	
	return(i);
}

