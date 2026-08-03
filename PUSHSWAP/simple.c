/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senandri <senandri@learner.tech.42>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 00:00:00 by senandri          #+#    #+#             */
/*   Updated: 2026/07/11 00:00:00 by senandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a, t_ops *ops)
{
	if (!*a || !(*a)->next || !(*a)->next->next)
		return ;
	if ((*a)->contenu > (*a)->next->contenu)
		op_sa(a, ops);
	if ((*a)->next->contenu > (*a)->next->next->contenu)
		op_rra(a, ops);
	if ((*a)->contenu > (*a)->next->contenu)
		op_sa(a, ops);
}

static int	find_min_pos(t_stack *a)
{
	int		min;
	int		pos;
	int		cur;
	t_stack	*node;

	min = a->contenu;
	pos = 0;
	cur = 0;
	node = a->next;
	while (node)
	{
		cur = cur + 1;
		if (node->contenu < min)
		{
			min = node->contenu;
			pos = cur;
		}
		node = node->next;
	}
	return (pos);
}

int	reach(int pos, int size)
{
	if (pos <= size / 2)
		return (pos);
	return (size - pos);
}

void	rotate_to_top(t_stack **a, int pos, int size, t_ops *ops)
{
	int	moves;

	if (pos <= size / 2)
	{
		moves = 0;
		while (moves < pos)
		{
			op_ra(a, ops);
			moves = moves + 1;
		}
	}
	else
	{
		moves = size - pos;
		while (moves > 0)
		{
			op_rra(a, ops);
			moves = moves - 1;
		}
	}
}

void	sort_simple(t_stack **a, t_stack **b, t_ops *ops)
{
	int	size;
	int	pos;

	size = stack_size(*a);
	if (size <= 1)
		return ;
	if (size == 2)
	{
		if ((*a)->contenu > (*a)->next->contenu)
			op_sa(a, ops);
		return ;
	}
	while (size > 3)
	{
		pos = find_min_pos(*a);
		rotate_to_top(a, pos, size, ops);
		op_pb(a, b, ops);
		size = size - 1;
	}
	sort_three(a, ops);
	while (*b)
		op_pa(a, b, ops);
}
