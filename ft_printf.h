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
}	t_printf;

char ft_tratament(const char *fp, va_list ap, int i);
void ft_char(char ap);
#endif