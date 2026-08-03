/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senandri <senandri@learner.tech.42>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 16:53:23 by senandri          #+#    #+#             */
/*   Updated: 2026/04/29 14:36:43 by senandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*p;
	int		i;

	p = lst;
	i = 0;
	while (p)
	{
		p = p->next;
		i++;
	}
	return (i);
}
/*
int	main(void)
{
	t_list	*node1 = ft_lstnew("cabinet");
	t_list	*node2 = ft_lstnew("guez");
	t_list	*node3 = ft_lstnew("guez");
	t_list	*node4 = ft_lstnew(".com");

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;

	ft_lstsize(node1);
	ft_putnbr_fd(ft_lstsize(node1), 1);
	ft_putchar_fd('\n', 1);
	return(0);
}
*/