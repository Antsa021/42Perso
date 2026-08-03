/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senandri <senandri@learner.tech.42>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 14:23:23 by senandri          #+#    #+#             */
/*   Updated: 2026/07/11 19:15:20 by senandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	on_rotate(t_stack **s)
{
	t_stack	*first;
	t_stack	*last;

	if (!*s || !(*s)->next)
		return ;
	first = *s;
	last = *s;
	while (last->next)
		last = last->next;
	*s = first->next;
	first->next = NULL;
	last->next = first;
}

void	op_ra(t_stack **a, t_ops *ops)
{
	on_rotate(a);
	ops->ra = ops->ra + 1;
	if (!ops->silent)
		ft_printf("ra\n");
}

void	op_rb(t_stack **b, t_ops *ops)
{
	on_rotate(b);
	ops->rb = ops->rb + 1;
	if (!ops->silent)
		ft_printf("rb\n");
}

void	op_rr(t_stack **a, t_stack **b, t_ops *ops)
{
	on_rotate(a);
	on_rotate(b);
	ops->rr = ops->rr + 1;
	if (!ops->silent)
		ft_printf("rr\n");
}
