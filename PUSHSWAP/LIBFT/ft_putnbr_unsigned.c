/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senandri <senandri@learner.tech.42>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 17:46:35 by senandri          #+#    #+#             */
/*   Updated: 2026/05/06 11:12:00 by senandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned(unsigned int n)
{
	int	compteur;

	compteur = 0;
	if (n >= 10)
		compteur = compteur + ft_putnbr_unsigned(n / 10);
	compteur = compteur + ft_putchar_count(((n % 10) + '0'));
	return (compteur);
}
