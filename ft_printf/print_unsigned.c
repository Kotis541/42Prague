/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokotera <vokotera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 16:03:30 by vokotera          #+#    #+#             */
/*   Updated: 2025/12/01 16:14:06 by vokotera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_unsigned(unsigned int n)
{
	int		count;
	char	res;

	count = 0;
	if (n >= 10)
		count += print_unsigned(n / 10);
	res = (n % 10) + '0';
	count += write(1, &res, 1);
	return (count);
}
