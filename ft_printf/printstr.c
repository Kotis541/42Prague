#include "ft_printf.h"

int	printstr(const char *s)
{
	int len;

	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = 0;
	while (*s)
	{
		printchar(*s);
		s++;
		len++;
	}
	return (len);
}
