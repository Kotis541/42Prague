#include "libft.h"

int	ft_printf(const char *format, ...)
{
	va_list args;
	size_t	count;
	int i;

	va_start(args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c')
			{
				ft_putchar_fd(va_arg(args, int), 1);
				i += 2;
			}
			else if (format[i + 1] == 's')
			{
				ft_putstr_fd(va_arg(args, char *), 1);
				i += 2;
			}
		}
		putchar(format[i++]);
	}
	va_end(args);
}

int main () {
	ft_printf("Cau ja jsem %s jsem %c of everyone co %s", "Vojta", '1', "ty");
}