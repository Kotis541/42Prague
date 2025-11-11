/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokotera <vokotera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 08:47:46 by vokotera          #+#    #+#             */
/*   Updated: 2025/11/11 10:13:20 by vokotera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

/*int main()
{
	char buff[20] = "hello world";

	ft_memset(buff,'*', 4);
	printf("String after memset(): %s \n", buff);
	ft_bzero(buff, 4);
	printf("String after memset(): %s \n", buff);
}8*/

