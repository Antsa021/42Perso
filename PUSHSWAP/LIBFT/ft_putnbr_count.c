/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senandri <senandri@learner.tech.42>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 17:46:35 by senandri          #+#    #+#             */
/*   Updated: 2026/05/06 11:01:52 by senandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_count(int n)
{
	int	compteur;

	compteur = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		compteur = compteur + ft_putchar_count('-');
		n = -n;
	}
	if (n >= 10)
		compteur = compteur + ft_putnbr_count(n / 10);
	compteur = compteur + ft_putchar_count(((n % 10) + '0'));
	return (compteur);
}
