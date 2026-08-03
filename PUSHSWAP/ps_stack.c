/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senandri <senandri@learner.tech.42>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 14:23:23 by senandri          #+#    #+#             */
/*   Updated: 2026/07/11 21:40:51 by senandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_dup(t_stack *a, int val)
{
	while (a)
	{
		if (a->contenu == val)
			return (1);
		a = a->next;
	}
	return (0);
}

t_stack	*stack_add_back(t_stack *head, int valeur)
{
	t_stack	*node;
	t_stack	*cur;

	node = malloc(sizeof(t_stack));
	if (!node)
		error_time(head);
	node->contenu = valeur;
	node->next = NULL;
	if (!head)
		return (node);
	cur = head;
	while (cur->next)
		cur = cur->next;
	cur->next = node;
	return (head);
}

int	stack_size(t_stack *a)
{
	int	n;

	n = 0;
	while (a)
	{
		n = n + 1;
		a = a->next;
	}
	return (n);
}

int	is_sorted(t_stack *a)
{
	while (a && a->next)
	{
		if (a->contenu > a->next->contenu)
			return (0);
		a = a->next;
	}
	return (1);
}

void	free_stack(t_stack *a)
{
	t_stack	*tmp;

	while (a)
	{
		tmp = a->next;
		free(a);
		a = tmp;
	}
}
