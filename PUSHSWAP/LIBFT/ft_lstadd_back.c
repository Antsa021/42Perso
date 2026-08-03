/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senandri <senandri@learner.tech.42>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 16:11:51 by senandri          #+#    #+#             */
/*   Updated: 2026/04/29 17:05:16 by senandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = new;
}
/*
int	main(void)
{
	t_list	*node1 = ft_lstnew("cabinet");
	t_list	*node2 = ft_lstnew("guez");
	t_list	*node3 = ft_lstnew("guez");
	t_list	*node4 = ft_lstnew(".com");
	t_list	*uno;
	t_list	*vraiuno;

	node1->next = node2;
	node2->next = node3;
	
	uno = node1;
	ft_lstadd_back(&uno, node4);
	
	vraiuno  = ft_lstlast(node1);
	ft_putstr_fd((char *)vraiuno->content, 1);
	ft_putchar_fd('\n', 1);
	return (0);
}
*/