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
	int i = 0;
	int size;

	size = ft_strlen(fp);
	va_start(ap, fp);  
	while (fp[i] != '\0' && i < size)
	{
		if (fp[i] == '%')
		{
			i = ft_tratament(fp, ap, i + 1);
		}
		else
			write(1, &fp[i], 1);
		i++;
	}
	va_end(ap);
	return 0;
}

int main()
{
	char *rafa;
	char *teste;
	char letra;
	char *string;

	rafa = "teste";
	letra = 'c';

	ft_printf("string = %-12345s\nchar = %c\npointer = %p\n", rafa, letra, string);
	
	return 0;
}
