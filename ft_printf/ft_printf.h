/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokotera <vokotera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:48:15 by vokotera          #+#    #+#             */
/*   Updated: 2025/11/27 16:35:27 by vokotera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdint.h> 

int	printchar(int c);
int	ft_printf(const char *format, ...);
int	printstr(const char *s);
int	printptr(void *ptr);
int tohex(uintptr_t decimal, int uppercase);
int	printdecimal(long n);
int	print_unsigned(unsigned long n);

#endif
