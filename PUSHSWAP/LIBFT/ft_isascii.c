/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senandri <senandri@learner.tech.42>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 17:16:19 by senandri          #+#    #+#             */
/*   Updated: 2026/04/24 20:40:38 by senandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
/*
int	main(void)
{
char	c = 'b';
int		resultat;

resultat = ft_isascii(c);
ft_putchar_fd(resultat + '0', 1);
ft_putchar_fd('\n', 1);
return (0);
}
*/
