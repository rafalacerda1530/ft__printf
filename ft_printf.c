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

#include "ft_printf.h"

int ft_printf(const char *fp, ...)
{
	va_list ap;
	int i = 0;

	va_start(ap, fp);
	while (i < ft_strlen(fp))
	{
		if (fp[i] == '%')
		{
			ft_tratament(fp, ap, i);
			i += 2;
		}
		write(1, &fp[i], 1);
		i++;
	}
	va_end(ap);
	return 0;
}

int main()
{
	char a = 'a';
	char b = 'b';
	ft_printf("teste = %c\nteste2 = %c\n", a, b);
}
