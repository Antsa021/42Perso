/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_lstnew.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: senandri <senandri@learner.42.tech>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/04 14:40:33 by senandri         #+#    #+#              */
/*   Updated: 2026/05/04 14:40:33 by senandri        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
	{
		return (NULL);
	}
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
