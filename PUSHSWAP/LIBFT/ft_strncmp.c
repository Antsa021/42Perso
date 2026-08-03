/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senandri <senandri@learner.tech.42>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 08:51:11 by senandri          #+#    #+#             */
/*   Updated: 2026/04/28 11:50:55 by senandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if (s1[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
char	tab[] = "patate";
char	tab2[] = "pouce";
int		resultat;
int		resultat2;

resultat = ft_strncmp(tab, tab2, 0);
ft_putnbr_fd(resultat, 1);
ft_putchar_fd('-', 1);
resultat2 = strncmp(tab, tab2, 0);
ft_putnbr_fd(resultat2, 1);
ft_putchar_fd('\n', 1);
return (0);
}
*/
