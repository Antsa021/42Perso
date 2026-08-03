/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   get_next_line_utils.c                             :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: senandri <senandri@learner.42.tech>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/06/23 16:00:13 by senandri         #+#    #+#              */
/*   Updated: 2026/06/23 16:01:54 by senandri        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char) c)
			return (&s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	size_t	i;
	size_t	j;

	res = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
	return (res);
}
