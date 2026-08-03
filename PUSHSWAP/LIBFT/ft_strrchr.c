/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senandri <senandri@learner.tech.42>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 08:42:15 by senandri          #+#    #+#             */
/*   Updated: 2026/04/24 20:44:19 by senandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	while (i != 0)
	{
		if (s[i] == (char) c)
			return ((char *) & s[i]);
		else
			i--;
	}
	if (s[i] == (char) c)
		return ((char *) & s[i]);
	return (NULL);
}
/*
int	main(void)
{
char	tab[] = "bonjour";
char	*resultat;
char	*resultat2;

resultat = ft_strrchr(tab, 106);
resultat2 = strrchr(tab, 106);
if (resultat)
ft_putchar_fd(*resultat, 1);
else
ft_putchar_fd('0', 1);
ft_putchar_fd('-', 1);
if (resultat2)
ft_putchar_fd(*resultat2, 1);
else
ft_putchar_fd('0', 1);
ft_putchar_fd('\n', 1);
return (0);
}
*/
