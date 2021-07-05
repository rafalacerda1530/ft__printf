/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printh.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarodrig <rarodrig@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 17:41:40 by rarodrig          #+#    #+#             */
/*   Updated: 2021/06/28 17:41:40 by rarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H


#include "libft/libft.h"
#include <stdarg.h>

typedef struct s_printf
{
	char letter;
	char *string;
	unsigned long int pointer;
	int index;
}	t_printf;

int ft_tratament(const char *fp, va_list ap, int i);
void ft_string(char *ap);
char ft_pointer(unsigned long int fp);
int ft_check(const char *fp, va_list ap, int i);
#endif
