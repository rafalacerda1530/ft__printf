#include "ft_printf.h"

void	ft_print_hex(char *str, t_flags *s_flags, va_list args)
{
	unsigned int	num;
	char			*str_num;
	int				rest_size;

	num = va_arg(args, unsigned int);
	str_num = ft_itoa_hex(num, s_flags, str);
	rest_size = s_flags->width - ft_strlen(str_num);
	s_flags->num = num;
	print_flags_hex(str, str_num, &rest_size, s_flags);
	free(str_num);
}

void	ft_print_pointer(va_list args, t_flags *s_flags, char *str)
{
	unsigned long long int	num;
	int						rest_size;
	char					*str_num;

	num = va_arg(args, unsigned long long int);
	str_num = ft_itoa_hex(num, s_flags, str);
	rest_size = (s_flags->width - (ft_strlen(str_num) + 2));
	printpointer_flags(&rest_size, str_num, s_flags);
	free(str_num);
}

void	ft_print_unsig(va_list args, t_flags *s_flags)
{
	unsigned int	num;
	char			*str_num;
	int				i;
	int				rest_size;

	i = 0;
	num = va_arg(args, unsigned int);
	str_num = ft_utoa(num);
	rest_size = (s_flags->width - ft_strlen(str_num));
	if ((s_flags->minus) && (rest_size > 0))
	{
		ft_putstr(&str_num[i], 1, s_flags);
		print_width(&rest_size, s_flags);
	}
	else
	{
		print_width(&rest_size, s_flags);
		ft_putstr(&str_num[i], 1, s_flags);
	}
	free(str_num);
}

void	ft_print_num(va_list args, t_flags *s_flags)
{
	int		num;
	char	*str_num;
	int		i;
	int		rest_size;

	i = 0;
	num = va_arg(args, int);
	str_num = ft_itoa(num);
	rest_size = (s_flags->width - ft_strlen(str_num));
	if ((s_flags->space) && num >= 0)
	{
		ft_putchar_fd(' ', 1, s_flags);
		rest_size--;
	}
	print_flags_num(&rest_size, str_num, num, s_flags);
	free(str_num);
}
