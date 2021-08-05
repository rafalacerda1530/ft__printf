#include "ft_printf.h"

int	ft_checklen_base(unsigned long long num)
{
	int	size;

	size = 1;
	while (num >= 16)
	{
		size++;
		num = num / 16;
	}
	return (size);
}

char	*ft_itoa_hex(unsigned long long num, t_flags *s_flags, char *str)
{
	char	*str_num;
	int		len;

	len = ft_checklen_base(num);
	str_num = (char *)malloc(sizeof(char) * len + 1);
	str_num[len] = '\0';
	while (len--)
	{
		if (str[s_flags->index] == 'X' && num % 16 >= 10)
			str_num[len] = (num % 16) - 10 + 'A';
		else if (num % 16 >= 10)
			str_num[len] = (num % 16) - 10 + 'a';
		else
			str_num[len] = (num % 16) + '0';
		num /= 16;
	}
	return (str_num);
}

void	print_flags_num(int *r_s, char *str_num, int num, t_flags *s_flags)
{
	int	i;

	i = 0;
	if ((num < 0) && (s_flags->zero == 1))
	{
		ft_putchar_fd('-', 1, s_flags);
		i++;
	}
	if ((s_flags->minus) && (r_s > 0))
	{
		if (s_flags->plus)
			ft_putchar_fd('+', 1, s_flags);
		ft_putstr(&str_num[i], 1, s_flags);
		print_width_num(r_s, s_flags, num);
	}
	else
	{
		print_width_num(r_s, s_flags, num);
		ft_putstr(&str_num[i], 1, s_flags);
	}
}

void	printpointer_flags(int *rest_size, char *str_num, t_flags *s_flags)
{
	if ((s_flags->minus) && (rest_size > 0))
	{
		ft_putstr("0x", 1, s_flags);
		ft_putstr(str_num, 1, s_flags);
		print_width(rest_size, s_flags);
	}
	else if ((s_flags->zero) && (rest_size > 0))
	{
		ft_putstr("0x", 1, s_flags);
		print_width(rest_size, s_flags);
		ft_putstr(str_num, 1, s_flags);
	}
	else
	{
		print_width(rest_size, s_flags);
		ft_putstr("0x", 1, s_flags);
		ft_putstr(str_num, 1, s_flags);
	}
}

void	print_flags_hex(char *str, char *str_num, int *r_s, t_flags *s_flags)
{	
	if (s_flags->zero)
	{
		print_hashtag(str, s_flags);
		print_width(r_s, s_flags);
		ft_putstr(str_num, 1, s_flags);
	}
	else if (s_flags->minus)
	{
		print_hashtag(str, s_flags);
		ft_putstr(str_num, 1, s_flags);
		print_width(r_s, s_flags);
	}
	else
	{
		print_width(r_s, s_flags);
		print_hashtag(str, s_flags);
		ft_putstr(str_num, 1, s_flags);
	}
}
