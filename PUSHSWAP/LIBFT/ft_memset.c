/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senandri <senandri@learner.tech.42>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 09:53:22 by senandri          #+#    #+#             */
/*   Updated: 2026/04/26 11:17:39 by senandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *src, int c, size_t n)
{
	unsigned char	*p;
	size_t			i;

	p = (unsigned char *) src;
	i = 0;
	while (i < n)
	{
		p[i] = (unsigned char) c;
		i++;
	}
	return (src);
}
/*
int	main(void)
{
	char	tab[] = "bonjour";
	int		i;

	ft_memset(tab, 120, 4);
	i = 0;
	while (i < 7)
	{
		ft_putchar_fd(tab[i], 1);
		i++;
	}
	ft_putchar_fd('\n', 1);
	return (0);
}
*/
