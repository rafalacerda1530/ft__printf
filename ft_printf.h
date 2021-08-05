#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_flags
{
	int	minus;
	int	zero;
	int	width;
	int	hashtag;
	int	index;
	int	plus;
	int	space;
	int	size;
	int	num;
}	t_flags;

int		ft_printf(const char *str, ...);
void	ft_check_sign(char *str, t_flags *s_flags);
void	ft_check_width(char *str, t_flags *s_flags, va_list args);
void	ft_parse_args(char *str, t_flags *s_flags, va_list args);
int		ft_strlen(char *str);
void	ft_putchar_fd(char c, int fd, t_flags *s_flags);
char	*ft_itoa(int num);
int		ft_checklen(int num);
void	ft_print_num(va_list args, t_flags *s_flags);
void	ft_print_char(va_list args, t_flags *s_flags);
void	ft_print_str(va_list args, t_flags *s_flags);
void	ft_print_unsig(va_list args, t_flags *s_flags);
void	ft_print_pointer(va_list args, t_flags *s_flags, char *str);
void	ft_print_hex(char *str, t_flags *s_flags, va_list args);
char	*ft_utoa(unsigned int num);
int		ft_check_unsig(unsigned int num);
void	ft_putnbr_hex(char *base, unsigned long long int num, t_flags *s_flags);
void	print_width(int *rest_size, t_flags *s_flags);
void	init_struct(t_flags *s_flags);
int		ft_atoi(char *str, t_flags *s_flags);
void	ft_result_flags(t_flags *s_flags);
void	ft_putstr(char *str, int fd, t_flags *s_flags);
char	*ft_itoa_hex(unsigned long long num, t_flags *s_flags, char *str);
int		ft_checklen_base(unsigned long long num);
void	print_width_num(int *rest_size, t_flags *s_flags, int num);
void	print_flags_num(int *r_s, char *str_num, int num, t_flags *s_flags);
void	printpointer_flags(int *rest_size, char *str_num, t_flags *s_flags);
void	check_hashtag(char *str, t_flags *s_flags);
void	print_hashtag(char *str, t_flags *s_flags);
void	ft_reset_flags(t_flags *s_flags);
void	print_flags_hex(char *str, char *str_num, int *r_s, t_flags *s_flags);

#endif