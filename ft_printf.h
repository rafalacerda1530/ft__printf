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


#include "libft_printf/libft.h"
#include <stdarg.h>
#include <stdio.h>


typedef struct s_printf
{
	char *conv;
	char letter;
	char *string;
	unsigned long int pointer;
	int width;
	int flag_minus;
	int flag_zero;
	int index;
	int flag_num;
	int cont;
	int cont_u;
	int i;
	int flag_dot;
	int precision;
	int iteration;
	int sub;

}	t_printf;

void ft_tratament(const char *fp, va_list ap, t_printf *content);
void ft_string(char *ap, t_printf *content);
void ft_pointer(unsigned long int fp, t_printf *content);
void ft_check(const char *fp, t_printf *content);
void ft_char(t_printf *content);
void 	ft_putnbr_base_fd(unsigned long int num, char *base, int fd, t_printf *content);
int ft_printf(const char *fp, ...);
void	ft_integer(char fp, int ap, t_printf *content);
int check_integer(char fp, int ap, t_printf *content);
void p_width(t_printf *content);
void p_int(t_printf *content);
void	ft_flag_u(char fp, unsigned int ap, t_printf *content);
void 	ft_putnbr_base_u(unsigned int num, char *base, int fd, char cv, t_printf *content);
void	ft_count_digits(unsigned long int num, char *base, t_printf *content);
void	ft_flag_x(char fp, unsigned int ap, t_printf *content);
#endif
