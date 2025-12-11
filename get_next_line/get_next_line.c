/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokotera <vokotera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 09:04:16 by vokotera          #+#    #+#             */
/*   Updated: 2025/12/11 10:25:02 by vokotera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*append_to_stash(char *stash, char *buff)
{
	char	*temp;

	if (!stash)
		return (ft_strdup(buff));
	temp = stash;
	stash = ft_strjoin(temp, buff);
	free(temp);
	return (stash);
}

static char	*fill_line_buffer(int fd, char *stash)
{
	char	*buff;
	int		bytes_read;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buff), free(stash), NULL);
		if (bytes_read == 0)
			break ;
		buff[bytes_read] = '\0';
		stash = append_to_stash(stash, buff);
		if (!stash)
			return (free(buff), NULL);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	free(buff);
	return (stash);
}

static char	*set_line(char *line_buffer)
{
	int		len;
	int		i;
	char	*buff;

	len = 0;
	while (line_buffer[len] && line_buffer[len] != '\n')
		len++;
	if (len == 0 && line_buffer[len] != '\n')
		return (NULL);
	buff = malloc(len + 2);
	if (!buff)
		return (NULL);
	i = -1;
	while (++i < len)
		buff[i] = line_buffer[i];
	if (line_buffer[len] == '\n')
		buff[i++] = '\n';
	buff[i] = '\0';
	return (buff);
}

static char	*clean_stash(char *newline, char *stash)
{
	size_t	start;
	char	*new_stash;

	start = (newline - stash) + 1;
	new_stash = ft_substr(stash, start, ft_strlen(stash) - start);
	free (stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*newline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = fill_line_buffer(fd, stash);
	if (!stash)
		return (NULL);
	line = set_line(stash);
	newline = ft_strchr(stash, '\n');
	if (!newline)
	{
		free(stash);
		stash = NULL;
	}
	else
		stash = clean_stash(newline, stash);
	return (line);
}

int main()
{
	int fd = open("file.txt",O_RDONLY);
	if (fd == -1)
		printf("%s", "Crashed");
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}
