/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senandri <senandri@learner.tech.42>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 17:03:02 by senandri          #+#    #+#             */
/*   Updated: 2026/04/29 20:24:32 by senandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/*
int	main(void)
{
char	tab[] = "Bonjour a tous";
int		combien;

combien = ft_strlen(tab);
ft_putnbr_fd(combien, 1);
ft_putchar_fd('\n', 1);
return (0);
}
*/
