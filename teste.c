#include <stdarg.h>
#include <stdio.h>

int sumnum(int num, ...)
{
	va_list ap;
	int cont;
	int sum = 0;

	va_start(ap, num);
	while (cont < num)
	{
		sum += va_arg(ap, int);

		cont++;
	}

	va_end(ap);

	return(sum);
}

void putstr(int num, ...)
{
	int count = 0;
	va_list ap;
	char *ptr;

	va_start(ap, num);
	while(count < num)
	{
		ptr = va_arg(ap, char *);
		if (*ptr > 1 && *ptr < 9)
			printf("foi\n");
		printf ("num = %s\n", ptr);

		count++;
	}

	va_end(ap);
}

int main()
{
	int total;

	total = sumnum(6, 3, 5, 7, 1, 5, "a");

	printf("%d\n", total);

	putstr(2, "one", "two", 1);

	return 0;
}