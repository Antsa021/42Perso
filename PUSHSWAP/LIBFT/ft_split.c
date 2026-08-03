/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senandri <senandri@learner.tech.42>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 16:01:50 by senandri          #+#    #+#             */
/*   Updated: 2026/05/04 14:48:22 by senandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	comptage_strings(char *s, char c)
{
	int	i;
	int	compteur;

	i = 0;
	compteur = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			compteur++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (compteur);
}

static char	*print_mot(char *s, int debut, int fin)
{
	char	*mot;
	int		i;

	mot = malloc(sizeof(char) * ((fin - debut) + 1));
	if (!mot)
		return (NULL);
	i = 0;
	while (debut < fin)
	{
		mot[i] = s[debut];
		i++;
		debut++;
	}
	mot[i] = '\0';
	return (mot);
}

static void	fill_tab(char **tab, char const *s, char c)
{
	int	i;
	int	j;
	int	debut;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			debut = i;
			while (s[i] && s[i] != c)
				i++;
			tab[j++] = print_mot((char *) s, debut, i);
		}
	}
	tab[j] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**tab;

	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * (comptage_strings((char *) s, c) + 1));
	if (!tab)
		return (NULL);
	fill_tab(tab, s, c);
	return (tab);
}
/*
int	main(void)
{
	char	tab[] = "CHOCAPICmMIELPOPSmCORNFLAKES";
	char	**resultat;
	int		i;

	resultat = ft_split(tab, 0);
	if (!resultat)
		return (1);
	i = 0;
	while (resultat[i])
	{
		ft_putstr_fd(resultat[i], 1);
		ft_putstr_fd(", ", 1);
		i++;
	}
	i = 0;
	while (resultat[i])
	{
		free(resultat[i]);
		i++;
	}
	free(resultat);
	ft_putchar_fd('\n', 1);
	return (0);
}
*/