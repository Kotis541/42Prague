/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printft_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokotera <vokotera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:48:54 by vokotera          #+#    #+#             */
/*   Updated: 2025/11/27 16:31:18 by vokotera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	solve(va_list *args, char format)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += printchar(va_arg(*args, int));
	else if (format == 's')
		count += printstr(va_arg(*args, char *));
	else if (format == 'p')
		count += printptr(va_arg(*args, void *));
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			count += solve(&args, *format);
			format++;
			continue ;
		}
		count += printchar(*format);
		format++;
	}
	va_end(args);
	return (count);
}

int main()
{
	printf("%d\n", ft_printf("ahoj %s", "cau"));
	printf("%d\n", printf("ahoj %s", "cau"));
}
