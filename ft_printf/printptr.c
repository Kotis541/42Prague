/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokotera <vokotera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:33:35 by vokotera          #+#    #+#             */
/*   Updated: 2025/12/01 16:05:52 by vokotera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printptr(void *ptr)
{
	int			count;
	uintptr_t	addr;

	count = 0;
	if (ptr == NULL)
		return (printstr("(nil)"));
	addr = (uintptr_t)ptr;
	count += printstr("0x");
	count += tohex(addr, 0);
	return (count);
}
