/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_striteri.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: senandri <senandri@learner.42.tech>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/04 14:42:22 by senandri         #+#    #+#              */
/*   Updated: 2026/05/04 14:42:22 by senandri        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (s == NULL || f == NULL)
	{
		return ;
	}
	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
