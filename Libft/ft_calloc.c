/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_calloc.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: senandri <senandri@learner.42.tech>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/04 14:38:13 by senandri         #+#    #+#              */
/*   Updated: 2026/05/06 15:08:12 by senandri        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	total;

	if (size != 0 && count > ((size_t) - 1 / size))
	{
		return (NULL);
	}
	total = count * size;
	ptr = malloc(total);
	if (ptr == NULL)
	{
		return (NULL);
	}
	ft_bzero(ptr, total);
	return (ptr);
}
