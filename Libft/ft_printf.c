/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokotera <vokotera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 12:45:04 by vokotera          #+#    #+#             */
/*   Updated: 2025/11/27 15:21:17 by vokotera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	tohex(size_t decimal, int fd)
{
	char		hexadecimal[100];
	const char	*digits = "0123456789abcdef";
	size_t		i;
	size_t		count;

	i = 0;
	count = 0;
	if (decimal == 0)
	{
		ft_putchar_fd('0', fd);
		return (1);
	}
	i = 0;
	while (decimal > 0)
	{
		hexadecimal[i++] = digits[decimal % 16];
		decimal /= 16;
	}
	while (i > 0)
	{
		ft_putchar_fd(hexadecimal[--i], fd);
		count++;
	}
	return (count);
}

void	ft_put_unsigned(unsigned int n)
{
	char	c;

	if (n >= 10)
		ft_put_unsigned(n / 10);
	c = (n % 10) + '0';
	ft_putchar_fd(c, 1);
}

static int	ft_pustr_count(char *s)
{
	size_t	len;

	len = ft_strlen(s);
	write(1, s, len);
	return (len);
}


static int	putptr(const char *ptr)
{
	size_t	count;
	size_t	addr;

	count = 0;
	addr = (size_t)ptr;
	count += ft_putstr_count("0x");
	count += tohex(addr);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	count;
	char	str;
	int		i;

	va_start(args, format);
	count = 0;
	i = -1;
	while (format[++i])
	{
		if (format[i] == '%' format[++i])
		{
			if (format[i] == 'c')
				count += ft_putchar_fd(va_arg(args, int), 1);
			else if (format[i] == 's')
				count += ft_putstr_count(str);
			else if (format[i] == 'p')
				count += putptr(va_arg(args, void *));
			else if (format[i] == 'd' || format[i + 1] == 'i')
				count += ft_putnbr_fd(va_arg(args, int), 1);
			else if (format[i] == 'u')
				count += ft_put_unsigned(va_arg(args, unsigned int));
			else if (format[i] == 'x')
				count += tohex(va_arg(args, unsigned int), 1);
			else
				count += ft_putchar_fd(format[i], 1);
		}
		else
			count += ft_putchar_fd(format[i], 1);
	}
	va_end(args);
	return (count);
}

int main () {
	printf("Number of chars written mine = %x\n", ft_printf("ahoj jak se mas muj hex: %d\n", 200));
	printf("Number of chars written real = %x\n", printf("ahoj jak se mas muj hex: %d\n", 200));
}