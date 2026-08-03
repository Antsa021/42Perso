/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senandri <senandri@learner.tech.42>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 19:40:34 by senandri          #+#    #+#             */
/*   Updated: 2026/04/25 20:17:01 by senandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*resultat;
	int		debut;
	int		fin;
	int		i;

	if (!s1 || !set)
		return (NULL);
	debut = 0;
	fin = ft_strlen(s1) - 1;
	while (s1[debut] && ft_in_set(s1[debut], set))
		debut++;
	while (fin > debut && ft_in_set(s1[fin], set))
		fin--;
	resultat = malloc(sizeof(char) * (fin - debut + 2));
	if (!resultat)
		return (NULL);
	i = 0;
	while (debut <= fin)
	{
		resultat[i] = s1[debut];
		i++;
		debut++;
	}
	resultat[i] = '\0';
	return (resultat);
}
/*
int main(void)
{
    char    tab[]= "xoxoxogossipgirlxoxoxo";
    char    tab2[] = "xo";
    char    *resultat;

    resultat = ft_strtrim(tab, tab2);
    ft_putstr_fd(resultat, 1);
    ft_putchar_fd('\n', 1);
    return (0);
}
*/