#include "ft_printf.h"

void	check_hashtag(char *str, t_flags *s_flags)
{
	if (str[s_flags->index] == '#')
	{
		s_flags->hashtag = 1;
		s_flags->index++;
	}
}

void	print_hashtag(char *str, t_flags *s_flags)
{
	if (s_flags->hashtag && s_flags->num != 0)
	{
		if (str[s_flags->index] == 'x')
			ft_putstr("0x", 1, s_flags);
		else
			ft_putstr("0X", 1, s_flags);
	}
}
