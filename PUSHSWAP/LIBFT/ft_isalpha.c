/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senandri <senandri@learner.tech.42>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 16:20:01 by senandri          #+#    #+#             */
/*   Updated: 2026/04/28 11:25:28 by senandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}
/*
int	main(void)
{
char	c = '0';
int		resultat;

resultat = ft_isalpha(c);
ft_putchar_fd(resultat + '0', 1);
ft_putchar_fd('\n', 1);
return (0);
}
*/
