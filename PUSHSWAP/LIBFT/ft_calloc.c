/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senandri <senandri@learner.tech.42>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 11:06:36 by senandri          #+#    #+#             */
/*   Updated: 2026/04/28 15:04:07 by senandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t n, size_t size)
{
	void	*nouvotab;

	if (n > ((size_t)(-1) / size))
		return (NULL);
	nouvotab = malloc(n * size);
	if (!nouvotab)
		return (NULL);
	ft_bzero(nouvotab, n * size);
	return (nouvotab);
}
/*
int	main(void)
{
char	*nouvotab;
int		i;

nouvotab = ft_calloc(5, 1);
i = 0;
while (nouvotab[i] != '\0')
{
ft_putchar_fd(nouvotab[i], 1);
i++;
}
free(nouvotab);
ft_putchar_fd('\n', 1);
return (0);
}
*/
