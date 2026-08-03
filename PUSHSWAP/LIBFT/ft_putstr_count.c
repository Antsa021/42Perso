/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senandri <senandri@learner.tech.42>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 17:46:35 by senandri          #+#    #+#             */
/*   Updated: 2026/05/06 11:03:01 by senandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_count(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar_count(s[i]);
		i++;
	}
	return (i);
}
