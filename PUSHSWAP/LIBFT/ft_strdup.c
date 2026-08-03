/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senandri <senandri@learner.tech.42>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 11:09:40 by senandri          #+#    #+#             */
/*   Updated: 2026/04/29 18:17:12 by senandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	i;
	size_t	taille;
	char	*nouvo_tab;

	if (!src)
		return (NULL);
	taille = ft_strlen(src);
	nouvo_tab = malloc(sizeof(char) * (taille + 1));
	if (!nouvo_tab)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		nouvo_tab[i] = src[i];
		i++;
	}
	nouvo_tab[i] = '\0';
	return (nouvo_tab);
}
/*
int	main(void)
{
char	tab[] = "cabinet guez-guez.com";
char	*nouvotab;

nouvotab = ft_strdup(tab);
ft_putstr_fd(nouvotab, 1);
free(nouvotab);
ft_putchar_fd('\n', 1);
return (0);
}
*/
