/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senandri <senandri@learner.tech.42>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 19:09:16 by senandri          #+#    #+#             */
/*   Updated: 2026/04/25 15:36:50 by senandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *src, size_t n)
{
	ft_memset(src, 0, n);
}
/*
int	main(void)
{
char	tab[] = "bonjour";
int		i;

ft_bzero(tab, 4);
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
