/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gparpine <gparpine@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:10:47 by gparpine          #+#    #+#             */
/*   Updated: 2023/10/23 18:39:14 by gparpine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*strdup_newline(char *s)
{
	char	*result;
	int		len;
	int		i;

	len = 0;
	i = 0;
	if (!s[len])
		return (NULL);
	while (s[len] && s[len] != '\n')
		len++;
	result = ft_calloc(len + 2, sizeof(char));
	if (!result)
		return (NULL);
	while (i <= len)
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*strtrim_newline(char *s)
{
	char	*result;
	size_t	i;
	size_t	j;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	result = ft_calloc(ft_strlen(s) - i, sizeof(char));
	if (!s)
		return (NULL);
	j = -1;
	while (++i < ft_strlen(s))
		result[++j] = s[i];
	result[++j] = '\0';
	free(s);
	return (result);
}

char	*read_into_buffer(int fd, char *buffer)
{
	char	*tmp;
	ssize_t	bytes_read;

	tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!tmp)
		return (NULL);
	bytes_read = 1;
	while (ft_strchr(buffer, '\n') == NULL && bytes_read != 0)
	{
		bytes_read = read(fd, tmp, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(tmp);
			free(buffer);
			return (NULL);
		}
		tmp[bytes_read] = '\0';
		buffer = ft_strjoin(buffer, tmp);
	}
	free(tmp);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_into_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
	next_line = strdup_newline(buffer);
	buffer = strtrim_newline(buffer);
	return (next_line);
}
/*
int	main(int argc, char const *argv[])
{
	int		fd;
	char	*line;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while ((line = get_next_line(fd)))
		{
			printf("%s", line);
			free(line);
		}
		close(fd);
	}
	return (0);
}
*/
