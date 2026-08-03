/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senandri <senandri@learner.tech.42>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 13:47:42 by senandri          #+#    #+#             */
/*   Updated: 2026/04/29 10:17:09 by senandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_char_cmb_malloc(int n)
{
	int	compteur;

	compteur = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		compteur++;
	while (n != 0)
	{
		n = n / 10;
		compteur++;
	}
	return (compteur);
}

static void	ft_putnbr_revisite(char *resultat, long nb, int len)
{
	while (nb > 0)
	{
		resultat[len - 1] = (nb % 10) + '0';
		nb = nb / 10;
		len--;
	}
}

char	*ft_itoa(int n)
{
	long	nb;
	char	*resultat;
	int		len;

	nb = n;
	len = ft_char_cmb_malloc(n);
	resultat = malloc(sizeof(char) * (len + 1));
	if (!resultat)
		return (NULL);
	resultat[len] = '\0';
	if (nb < 0)
	{
		resultat[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		resultat[0] = '0';
	else
		ft_putnbr_revisite(resultat, nb, len);
	return (resultat);
}
/*
int	main(void)
{
	char	*resultat;

	resultat = ft_itoa(-532);
	ft_putstr_fd(resultat, 1);
	ft_putchar_fd('\n', 1);
	return (0);
}
*/