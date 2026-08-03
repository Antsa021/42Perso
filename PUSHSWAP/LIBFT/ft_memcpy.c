/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senandri <senandri@learner.tech.42>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 14:44:19 by senandri          #+#    #+#             */
/*   Updated: 2026/04/30 14:27:43 by senandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;
	size_t				i;

	s = (const unsigned char *) src;
	d = (unsigned char *) dest;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
/*
int	main(void)
{
char	tab[] = "bonsoir";
char	tab2[] = "zbeulzbeulzbeul";
int		i;

ft_memcpy(tab2, tab, 5);
i = 0;
while (i < 15)
{
ft_putchar_fd(tab2[i], 1);
i++;
}
ft_putchar_fd('\n', 1);
return (0);
}
*/
