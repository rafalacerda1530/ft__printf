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

int main()
{
	char *rafa;
	char *teste;
	char letra;
	char *string;

	rafa = "teste";
	letra = 'c';
	ft_printf("teste = %010crafa\n", letra);
	ft_printf("teste = %-10srafa  pointer = %-100prafa  pointer = %-100prafa\n", rafa, string);
	ft_printf("teste = %prafa\n", string);
	printf("teste = %c\n", letra);
	printf("teste = %-10srafa  pointer = %-100prafa  pointer = %-100prafa\n", rafa, string);
	printf("teste = %prafa\n", string);
	ft_printf("string = %-15s\nchar = %c   \npointer = %p\n", rafa, letra, string);
	printf("printf : \nstring = %-15s\nchar = %c   \npointer = %p\n", rafa, letra, string);
	
	return 0;
}
