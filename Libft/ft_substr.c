#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*arr;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (start + len > s_len)
		len = s_len - start;
	arr = malloc(len + 1);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		arr[i] = s[start + i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
