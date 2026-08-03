/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senandri <senandri@learner.tech.42>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 14:31:05 by senandri          #+#    #+#             */
/*   Updated: 2026/04/29 11:32:55 by senandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newnode;

	newnode = malloc(sizeof(t_list));
	if (!newnode)
		return (NULL);
	newnode->content = content;
	newnode->next = NULL;
	return (newnode);
}
/*
int	main(void)
{
	t_list	*newnode; 
	
	newnode= ft_lstnew("bonsooiiiiir");
	ft_putstr_fd((char *)newnode->content, 1);
	ft_putchar_fd('\n', 1);
	return (0);
}
*/