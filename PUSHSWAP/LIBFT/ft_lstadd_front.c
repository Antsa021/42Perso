/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senandri <senandri@learner.tech.42>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 15:17:06 by senandri          #+#    #+#             */
/*   Updated: 2026/04/29 11:47:09 by senandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	new->next = *lst;
	*lst = new;
}
/*
int	main(void)
{
	t_list *uno;
	t_list	*node1 = ft_lstnew("guez guez.com");
	t_list	*node2 = ft_lstnew("cabinet ");

	uno = node1;
	ft_lstadd_front(&uno, node2);
	
	ft_putstr_fd((char *)uno->content, 1);
	ft_putstr_fd((char *)uno->next->content, 1);
	ft_putchar_fd('\n', 1);
	return (0);
}
*/