#include "ft_printf.h"

int	printdecimal(long n)
{
	char	res;
	int		count;

	res = 0;
	count = 0;
	if (n < 0)
	{
		count += write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		count += printdecimal(n / 10);
	res = (n % 10) + '0';
	count += write(1, &res , 1);
	return (count);
}