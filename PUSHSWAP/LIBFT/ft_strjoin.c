/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senandri <senandri@learner.tech.42>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 12:55:37 by senandri          #+#    #+#             */
/*   Updated: 2026/04/25 15:52:51 by senandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	taille_nouvotab;
	size_t	i;
	size_t	j;
	char	*nouvotab;

	if (!s1 || !s2)
		return (NULL);
	taille_nouvotab = ft_strlen(s1) + ft_strlen(s2);
	nouvotab = malloc(taille_nouvotab + 1);
	if (!nouvotab)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		nouvotab[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		nouvotab[i++] = s2[j++];
	}
	nouvotab[i] = '\0';
	return (nouvotab);
}
/*
int	main(void)
{
char	tab[] = "bonsoir";
char	tab2[] = "paris";
char	*nouvotab;

nouvotab = ft_strjoin(tab, tab2);
ft_putstr_fd(nouvotab, 1);
free(nouvotab);
ft_putchar_fd('\n', 1);
return (0);
}
*/
