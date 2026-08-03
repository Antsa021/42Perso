/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senandri <senandri@learner.tech.42>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 09:12:27 by senandri          #+#    #+#             */
/*   Updated: 2026/04/30 16:30:16 by senandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	if (!little || little[0] == '\0')
		return ((char *) big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i] != little[j] && i < len)
			i++;
		k = i;
		while (big[i] == little[j] && i < len)
		{
			i++;
			j++;
		}
		if (little[j] == '\0')
			return ((char *) & big[k]);
		i = k + 1;
	}
	return (NULL);
}
/*
int	main(void)
{
char	little[] = "jour";
char	big[] = "bonjour";
char	*resultat;

resultat = ft_strnstr(big, little, 7);
if (resultat)
ft_putstr_fd(resultat, 1);
else
ft_putstr_fd("NULL", 1);
ft_putchar_fd('\n', 1);
return (0);
}
*/