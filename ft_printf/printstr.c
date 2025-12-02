/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokotera <vokotera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 16:04:31 by vokotera          #+#    #+#             */
/*   Updated: 2025/12/01 16:17:47 by vokotera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printstr(const char *s)
{
	int	len;

	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = 0;
	while (*s)
	{
		if (printchar(*s))
		{
			s++;
			len++;
		}
		else
			return (-1);
	}
	return (len);
}
