/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_strchrchar.c                                   :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: senandri <senandri@learner.42.tech>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/04 14:36:44 by senandri         #+#    #+#              */
/*   Updated: 2026/05/04 14:41:46 by senandri        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*result;

	i = 0;
	result = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
		{
			result = (char *) & s[i];
		}
		i++;
	}
	if ((char) c == '\0')
	{
		return ((char *) & s[i]);
	}
	return (result);
}
