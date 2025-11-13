#include "libft.h"

char *ft_strdup(const char *s)
{
	char	*arr;
	size_t	i;
	size_t 	len;

	len = ft_strlen(s);
	arr = malloc(len + 1);
	if (!arr)
		return (NULL);
	i = 0;
	while (s[i])
	{
		arr[i] = s[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
