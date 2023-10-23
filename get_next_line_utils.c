/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gparpine <gparpine@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:11:09 by gparpine          #+#    #+#             */
/*   Updated: 2023/10/23 18:39:17 by gparpine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n--)
		*p++ = 0;
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (0);
	while (*s && (unsigned char)c != *s)
		s++;
	if ((unsigned char)c == *s)
		return ((char *)s);
	return (0);
}

char	*ft_strjoin(char *buffer, char *temp)
{
	char	*result;
	size_t	i;
	size_t	j;

	i = -1;
	j = -1;
	if (!buffer)
		buffer = ft_calloc(1, sizeof(char));
	result = ft_calloc(ft_strlen(buffer) + ft_strlen(temp) + 1, sizeof(char));
	if (!result)
		return (NULL);
	while (buffer[++i])
		result[i] = buffer[i];
	while (temp[++j])
		result[j + i] = temp[j];
	result[i + j] = '\0';
	free(buffer);
	return (result);
}
