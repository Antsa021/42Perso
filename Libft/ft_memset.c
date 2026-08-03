/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_memset.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: senandri <senandri@learner.42.tech>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/04 14:40:58 by senandri         #+#    #+#              */
/*   Updated: 2026/05/04 14:40:58 by senandri        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *) b;
	i = 0;
	while (i < len)
	{
		ptr[i] = (unsigned char) c;
		i++;
	}
	return (b);
}
