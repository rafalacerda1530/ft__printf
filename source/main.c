#include "../ft_printf.h"

int main()
{
	printf("retorno = %d", ft_printf("%.5s%7s", "yo", "boi"));
	printf("\n");
	printf("retorno = %d", printf("%.5s%7s", "yo", "boi"));
}
