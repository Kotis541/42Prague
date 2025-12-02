/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tohex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokotera <vokotera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 16:05:31 by vokotera          #+#    #+#             */
/*   Updated: 2025/12/01 16:05:37 by vokotera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	tohex(uintptr_t decimal, int uppercase)
{
	char	buff[20];
	int		count;
	int		i;
	char	*hex_digits;

	if (uppercase)
		hex_digits = "0123456789ABCDEF";
	else
		hex_digits = "0123456789abcdef";
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
