/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senandri <senandri@learner.tech.42>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 17:52:18 by senandri          #+#    #+#             */
/*   Updated: 2026/04/27 20:10:36 by senandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*suivant;

	if (!lst || !del)
		return ;
	current = *lst;
	while (current)
	{
		suivant = current->next;
		del(current->content);
		free(current);
		current = suivant;
	}
	*lst = NULL;
}
