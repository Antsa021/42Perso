/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senandri <senandri@learner.tech.42>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 14:23:23 by senandri          #+#    #+#             */
/*   Updated: 2026/07/11 21:30:29 by senandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	on_push(t_stack **from, t_stack **to)
{
	t_stack	*node;

	if (!*from)
		return ;
	node = *from;
	*from = (*from)->next;
	node->next = *to;
	*to = node;
}

void	op_pa(t_stack **a, t_stack **b, t_ops *ops)
{
	on_push(b, a);
	ops->pa = ops->pa + 1;
	if (!ops->silent)
		ft_printf("pa\n");
}

void	op_pb(t_stack **a, t_stack **b, t_ops *ops)
{
	on_push(a, b);
	ops->pb = ops->pb + 1;
	if (!ops->silent)
		ft_printf("pb\n");
}
