#include "ft_printf.h"

void	print_width(int *rest_size, t_flags *s_flags)
{
	if (s_flags->hashtag)
		*rest_size = *rest_size - 2;
	if ((s_flags->zero) && (*rest_size > 0))
	{
		while (*rest_size > 0)
		{
			ft_putchar_fd('0', 1, s_flags);
			*rest_size = *rest_size - 1;
		}
	}
	else
	{
		while (*rest_size > 0)
		{
			ft_putchar_fd(' ', 1, s_flags);
			*rest_size = *rest_size - 1;
		}
	}
}

void	print_width_num(int *rest_size, t_flags *s_flags, int num)
{
	if ((s_flags->zero) && (*rest_size > 0))
	{
		if ((num > 0) && (s_flags->plus))
		{
			ft_putchar_fd('+', 1, s_flags);
			*rest_size = *rest_size - 1;
		}
		while (*rest_size > 0)
		{
			ft_putchar_fd('0', 1, s_flags);
			*rest_size = *rest_size - 1;
		}
	}
	else
	{
		if (s_flags->plus)
			*rest_size = *rest_size - 1;
		while (*rest_size > 0)
		{
			ft_putchar_fd(' ', 1, s_flags);
			*rest_size = *rest_size - 1;
		}
		if ((s_flags->plus) && (num >= 0) && (s_flags->minus == 0))
			ft_putchar_fd('+', 1, s_flags);
	}
}
