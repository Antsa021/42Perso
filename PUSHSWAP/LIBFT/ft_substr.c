/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senandri <senandri@learner.tech.42>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 20:07:29 by senandri          #+#    #+#             */
/*   Updated: 2026/04/24 20:44:28 by senandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	longueur_de_s;
	char	*substring;

	if (!s)
		return (NULL);
	longueur_de_s = ft_strlen(s);
	if (start > longueur_de_s)
		len = 0;
	if (len > longueur_de_s - start)
		len = longueur_de_s - start;
	substring = malloc(sizeof(char) * (len + 1));
	if (!substring)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substring[i] = s[start + i];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}
/*
int	main(void)
{
char	tab[] = "bonjour";
char	*substring;

substring = ft_substr(tab, 3, 10);
ft_putstr_fd(substring, 1);
ft_putchar_fd('\n', 1);
return (0);
}
*/
