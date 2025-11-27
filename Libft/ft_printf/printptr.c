/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokotera <vokotera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:33:35 by vokotera          #+#    #+#             */
/*   Updated: 2025/11/27 16:33:49 by vokotera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printptr(void *ptr)
{
	int	count;
	int	addr;

	count = 0;
	addr = (int) ptr;
	count += printstr("0x");
	count += tohex(addr);
	return (count);
}