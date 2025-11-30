#include "ft_printf.h"

int tohex(uintptr_t decimal, int uppercase)
{
	char	*hex_lower = "0123456789abcdef";
	char	*hex_upper = "0123456789ABCDEF";
	char	buff[20];
	int		count;
	int		i;
	char	*hex_digits;

	if (uppercase)
		hex_digits = hex_upper;
	else 
		hex_digits = hex_lower;
	if (decimal == 0)
		return (write(1, "0", 1));
	i = 0;
	count = 0;
	while (decimal > 0)
	{
		buff[i++] = hex_digits[decimal % 16];
		decimal /= 16;
	}
	while (i > 0)
		count += write(1, &buff[--i], 1);
	return (count);
}