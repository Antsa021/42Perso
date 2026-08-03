/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convhexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senandri <senandri@learner.tech.42>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 17:46:35 by senandri          #+#    #+#             */
/*   Updated: 2026/05/06 10:59:36 by senandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convhexa(unsigned long n, char *base)
{
	int	compteur;

	compteur = 0;
	if (n >= 16)
		compteur = ft_convhexa(n / 16, base);
	compteur = compteur + ft_putchar_count(base[n % 16]);
	return (compteur);
}
