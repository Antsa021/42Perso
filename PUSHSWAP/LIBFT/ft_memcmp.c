/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senandri <senandri@learner.tech.42>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 15:09:37 by senandri          #+#    #+#             */
/*   Updated: 2026/04/24 20:41:16 by senandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*src1;
	unsigned char	*src2;
	size_t			i;

	src1 = (unsigned char *) s1;
	src2 = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (src1[i] == src2[i])
			i++;
		else
			return (src1[i] - src2[i]);
	}
	return (0);
}
/*
int	main(void)
{
char	tab[] = "bonjour";
char	tab2[] = "bonsoir";
int		resultat;
int		resultat2;

resultat = ft_memcmp(tab, tab2, 7);
ft_putnbr_fd(resultat, 1);
ft_putchar_fd('-', 1);
resultat2 = memcmp(tab, tab2, 7);
ft_putnbr_fd(resultat2, 1);
ft_putchar_fd('\n', 1);
return (0);
}
*/
