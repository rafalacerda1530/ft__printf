#include "../ft_printf.h"

int main()
{
	printf("retorno = %d", ft_printf("|%23s|", NULL));
	printf("\n");
	printf("retorno = %d", printf("|%23s|", NULL));
}
