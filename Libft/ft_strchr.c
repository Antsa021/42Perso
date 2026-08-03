/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_strchr.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: senandri <senandri@learner.42.tech>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/04 14:33:55 by senandri         #+#    #+#              */
/*   Updated: 2026/05/04 18:22:16 by senandri        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
		{
			return ((char *) & s[i]);
		}
		i++;
	}
	if ((char) c == '\0')
	{
		return ((char *) & s[i]);
	}
	return (NULL);
}
