/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senandri <senandri@learner.tech.42>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 18:18:56 by senandri          #+#    #+#             */
/*   Updated: 2026/04/30 16:22:18 by senandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
/*
int	main(void)
{
char	tab[] = "bonjour";
char	tab2[] = "bonsoir";
size_t	resultat;
size_t	resultat2;

resultat = ft_strlcpy(tab2, tab, 4);
resultat2 = strlcpy(tab2, tab, 4);
ft_putnbr_fd(resultat, 1);
ft_putnbr_fd(resultat2, 1);
ft_putchar_fd('\n', 1);
return (0);
}
*/
