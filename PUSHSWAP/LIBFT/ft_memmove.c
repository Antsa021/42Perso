/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senandri <senandri@learner.tech.42>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 10:08:34 by senandri          #+#    #+#             */
/*   Updated: 2026/04/29 17:52:39 by senandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;
	size_t				i;

	s = (const unsigned char *) src;
	d = (unsigned char *) dest;
	if (s > d)
	{
		i = 0;
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	else if (d > s)
	{
		i = n;
		while (i > 0)
		{
			i--;
			d[i] = s[i];
		}
	}
	return (dest);
}
/*
int	main(void)
{
	char	tab[] = "abcdefgh";
	int		i;

	ft_memmove(tab + 2, tab, 8);
	i = 0;
	while (i < 8)
	{
		ft_putchar_fd(tab[i], 1);
		i++;
	}
	ft_putchar_fd('\n', 1);
	return (0);
}
*/
