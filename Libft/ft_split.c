/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_split.c                                        :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: senandri <senandri@learner.42.tech>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/04 14:41:24 by senandri         #+#    #+#              */
/*   Updated: 2026/05/04 17:27:13 by senandri        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
		{
			i++;
		}
		if (s[i] != '\0')
		{
			count++;
		}
		while (s[i] != '\0' && s[i] != c)
		{
			i++;
		}
	}
	return (count);
}

static char	*ft_word_dup(char const *s, size_t start, size_t end)
{
	char	*word;
	size_t	i;

	word = malloc(sizeof(char) * (end - start + 1));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (start < end)
	{
		word[i] = s[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

static int	ft_add_word(char **split, char const *s, size_t *j, size_t pos[2])
{
	size_t	i;

	split[*j] = ft_word_dup(s, pos[0], pos[1]);
	if (split[*j] != NULL)
	{
		*j = *j + 1;
		return (1);
	}
	i = 0;
	while (i < *j)
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (0);
}

static int	ft_fill_split(char **split, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	pos[2];

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		pos[0] = i;
		while (s[i] != '\0' && s[i] != c)
			i++;
		pos[1] = i;
		if (pos[0] < pos[1] && ft_add_word(split, s, &j, pos) == 0)
			return (0);
	}
	split[j] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	if (s == NULL)
		return (NULL);
	split = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (split == NULL)
		return (NULL);
	if (ft_fill_split(split, s, c) == 0)
		return (NULL);
	return (split);
}
