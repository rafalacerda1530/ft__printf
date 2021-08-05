#include "ft_printf.h"

int	ft_atoi(char *str, t_flags *s_flags)
{
	int	res;

	res = 0;
	while ((str[s_flags->index] >= '0') && (str[s_flags->index] <= '9'))
	{
		res = (res * 10) + (str[s_flags->index] - '0');
		s_flags->index++;
	}
	return (res);
}

int	ft_check_unsig(unsigned int num)
{
	int	i;

	i = 1;
	while (num >= 10)
	{
		i++;
		num = num / 10;
	}
	return (i);
}

int	ft_checklen(int num)
{
	int				i;

	i = 0;
	if (num == 0)
		return (1);
	while (num && ++i)
		num = num / 10;
	return (i);
}

char	*ft_utoa(unsigned int num)
{
	char	*str;
	int		len;

	len = ft_check_unsig(num);
	str = (char *)malloc(sizeof(char) * len + 1);
	str[len] = '\0';
	while (len--)
	{
		str[len] = (num % 10) + '0';
		num = num / 10;
	}
	return (str);
}

char	*ft_itoa(int num)
{
	char			*str;
	int				len;
	unsigned int	n;
	int				neg;

	len = ft_checklen(num);
	neg = 0;
	if (num < 0)
	{
		num *= -1;
		n = num;
		neg = 1;
		len++;
	}
	str = (char *)malloc(sizeof(char) * len + 1);
	n = num;
	str[len] = '\0';
	while (len--)
	{
		str[len] = (n % 10) + '0';
		n = n / 10;
	}
	if (neg)
		str[0] = '-';
	return (str);
}
