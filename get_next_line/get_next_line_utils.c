/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokotera <vokotera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 09:03:57 by vokotera          #+#    #+#             */
/*   Updated: 2025/12/11 09:13:43 by vokotera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*arr;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	arr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!arr)
		return (NULL);
	i = 0;
	while (*s1)
		arr[i++] = *s1++;
	while (*s2)
		arr[i++] = *s2++;
	arr[i] = '\0';
	return (arr);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*arr;
	size_t	strlen;
	size_t	i;

	if (!s)
		return (NULL);
	strlen = ft_strlen(s);
	if (start >= strlen)
		return (ft_strdup(""));
	if (len > strlen - start)
		len = strlen - start;
	arr = malloc(len + 1);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < len)
		arr[i++] = s[start++];
	arr[i] = '\0';
	return (arr);
}

char	*ft_strdup(const char *s)
{
	char	*arr;
	int		i;

	arr = malloc(ft_strlen(s) + 1);
	if (!arr)
		return (NULL);
	i = 0;
	while (*s)
	{
		arr[i++] = *s++;
	}
	arr[i] = '\0';
	return (arr);
}
