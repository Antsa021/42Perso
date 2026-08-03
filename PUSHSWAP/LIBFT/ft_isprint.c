/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senandri <senandri@learner.tech.42>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 17:06:01 by senandri          #+#    #+#             */
/*   Updated: 2026/04/24 20:40:57 by senandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
/*
int	main(void)
{
char	c = '\v';
int		resultat;

resultat = ft_isprint(c);
ft_putchar_fd(resultat + '0', 1);
ft_putchar_fd('\n', 1);
return (0);
}
*/
