/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senandri <senandri@learner.tech.42>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 17:14:55 by senandri          #+#    #+#             */
/*   Updated: 2026/04/24 20:44:36 by senandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}
/*
int	main(void)
{
char	c = 'B';
int		resultat;

resultat = ft_tolower(c);
ft_putchar_fd(resultat, 1);
ft_putchar_fd('\n', 1);
return (0);
}
*/
