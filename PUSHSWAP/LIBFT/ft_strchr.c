/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senandri <senandri@learner.tech.42>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 08:19:01 by senandri          #+#    #+#             */
/*   Updated: 2026/04/29 18:39:38 by senandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			return ((char *) & s[i]);
		else
			i++;
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

resultat = ft_strchr(tab, 0);
resultat2 = strchr(tab, 0);
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
