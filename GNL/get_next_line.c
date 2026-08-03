/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   get_next_line.c                                   :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: senandri <senandri@learner.42.tech>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/06/23 15:59:39 by senandri         #+#    #+#              */
/*   Updated: 2026/06/23 15:59:39 by senandri        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*stashlibererdelivrer(char *stash)
{
	free(stash);
	return (NULL);
}

static char	*read_to_stash(int fd, char *stash)
{
	char	*buffer;
	char	*tmp;
	ssize_t	bytes;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (stashlibererdelivrer(stash));
	bytes = 1;
	while (!ft_strchr(stash, '\n') && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			return (stashlibererdelivrer(stash));
		}
		buffer[bytes] = '\0';
		tmp = stash;
		stash = ft_strjoin(stash, buffer);
		free(tmp);
	}
	free(buffer);
	return (stash);
}

static char	*extract_line(char *stash)
{
	char	*line;
	size_t	i;

	if (!stash || !stash[0])
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*maj_stash(char *stash)
{
	char	*rest;
	size_t	i;
	size_t	len;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (stashlibererdelivrer(stash));
	i++;
	len = ft_strlen(stash + i);
	rest = malloc(len + 1);
	if (!rest)
		return (stashlibererdelivrer(stash));
	len = 0;
	while (stash[i])
		rest[len++] = stash[i++];
	rest[len] = '\0';
	free(stash);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_to_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	stash = maj_stash(stash);
	return (line);
}
