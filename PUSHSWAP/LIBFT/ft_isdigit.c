/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senandri <senandri@learner.tech.42>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 16:41:27 by senandri          #+#    #+#             */
/*   Updated: 2026/04/25 15:53:15 by senandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
/*
int	main(void)
{
	char	c = 'a';
	int		resultat;

	resultat = ft_isdigit(c);
	ft_putchar_fd(resultat + '0', 1);
	ft_putchar_fd('\n', 1);
	return (0);
}
*/