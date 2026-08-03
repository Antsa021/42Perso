/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senandri <senandri@learner.tech.42>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 14:48:50 by senandri          #+#    #+#             */
/*   Updated: 2026/04/24 20:41:05 by senandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	const unsigned char	*s;
	size_t				i;

	s = (const unsigned char *) src;
	i = 0;
	while (i < n)
	{
		if (s[i] == (unsigned char) c)
			return ((void *) & s[i]);
		else
			i++;
	}
	return (NULL);
}
/*
int	main(void)
{
char	tab[] = "bonjour";
char	*resultat;

resultat = ft_memchr(tab, 106, 7);
if (resultat)
ft_putchar_fd(*resultat, 1);
else
ft_putchar_fd('0', 1);
ft_putchar_fd('\n', 1);
return (0);
}
*/
