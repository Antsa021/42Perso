/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senandri <senandri@learner.tech.42>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 19:41:27 by senandri          #+#    #+#             */
/*   Updated: 2026/04/25 20:54:00 by senandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	length;
	char			*resultat;

	if (!s || !f)
		return (NULL);
	length = ft_strlen(s);
	resultat = malloc(sizeof(char) * (length + 1));
	if (!resultat)
		return (NULL);
	i = 0;
	while (i < length)
	{
		resultat[i] = f(i, s[i]);
		i++;
	}
	resultat[i] = '\0';
	return (resultat);
}
/*
int	main(void)
{
char	tab[] = "bonjour";
char	*resultat;

resultat = ft_strmapi(tab, &ft_toupper);
ft_putstr_fd(resultat, 1);
free(resultat);
ft_putchar_fd('\n', 1);
return (0);
}
je vais pas te mentir ma soeur le main marche pas
*/
