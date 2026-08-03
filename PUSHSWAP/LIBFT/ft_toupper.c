/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senandri <senandri@learner.tech.42>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 17:13:30 by senandri          #+#    #+#             */
/*   Updated: 2026/04/25 14:34:13 by senandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

/*
int	main(void)
{
char	c = 'b';
int		resultat;

resultat = ft_toupper(c);
ft_putchar_fd(resultat, 1);
ft_putchar_fd('\n', 1);
return (0);
}
*/
