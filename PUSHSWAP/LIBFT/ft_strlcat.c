/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senandri <senandri@learner.tech.42>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 18:56:41 by senandri          #+#    #+#             */
/*   Updated: 2026/04/30 14:54:31 by senandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dst_initial;

	i = 0;
	j = 0;
	while (dst[i])
		i++;
	dst_initial = i;
	if (size <= dst_initial)
		return (size + ft_strlen(src));
	while (src[j] && i < size - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dst_initial + ft_strlen(src));
}
/*
int	main(void)
{
char	tab[] = "bonsoir";
char	tab2[] = "bonjour";
size_t	resultat;
size_t	resultat2;

resultat = ft_strlcat(tab2, tab, 8);
resultat2 = strlcat(tab2, tab, 8);
ft_putnbr_fd(resultat, 1);
ft_putchar_fd('-', 1);
ft_putnbr_fd(resultat2, 1);
ft_putchar_fd('\n', 1);
return (0);
}
*/
