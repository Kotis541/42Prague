#include "ft_printf.h"

int	print_unsigned(unsigned long n)
{
	int	count;
	char res;

	count = 0;
	if (n >= 10)
		count += print_unsigned(n / 10);
	res = (n % 10) + '0';
	count += write(1, &res, 1);
	return (count);
}