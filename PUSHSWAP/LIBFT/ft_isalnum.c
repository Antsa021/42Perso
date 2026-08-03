/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senandri <senandri@learner.tech.42>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 16:43:46 by senandri          #+#    #+#             */
/*   Updated: 2026/04/25 15:50:44 by senandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (((c >= 'A' && c <= 'Z') || (c
				>= 'a' && c <= 'z') || (c >= '0' && c <= '9')));
}
/*
int	main(void)
{
	char	c = '~';
	int		resultat;

	resultat = ft_isalnum(c);
	ft_putchar_fd(resultat + '0', 1);
	ft_putchar_fd('\n', 1);
	return (0);
}
*/
