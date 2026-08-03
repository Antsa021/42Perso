/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senandri <senandri@learner.tech.42>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 17:01:01 by senandri          #+#    #+#             */
/*   Updated: 2026/04/29 15:24:13 by senandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last;

	if (!lst)
		return (NULL);
	last = lst;
	while (last->next)
		last = last->next;
	return (last);
}
/*
int	main(void)
{
	t_list	*node1 = ft_lstnew("cabinet");
	t_list	*node2 = ft_lstnew("guez");
	t_list	*node3 = ft_lstnew("guez");
	t_list	*node4 = ft_lstnew(".com");
	t_list	*uno;

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;

	uno  = ft_lstlast(node1);
	ft_putstr_fd((char *)uno->content, 1);
	ft_putchar_fd('\n', 1);
	return(0);
}
*/