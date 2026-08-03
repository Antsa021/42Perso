/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senandri <senandri@learner.tech.42>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 14:23:23 by senandri          #+#    #+#             */
/*   Updated: 2026/07/11 19:15:20 by senandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_rrotate(t_stack **s)
{
	t_stack	*prev;
	t_stack	*last;

	if (!*s || !(*s)->next)
		return ;
	prev = *s;
	while (prev->next->next)
		prev = prev->next;
	last = prev->next;
	prev->next = NULL;
	last->next = *s;
	*s = last;
}

void	op_rra(t_stack **a, t_ops *ops)
{
	do_rrotate(a);
	ops->rra = ops->rra + 1;
	if (!ops->silent)
		ft_printf("rra\n");
}

void	op_rrb(t_stack **b, t_ops *ops)
{
	do_rrotate(b);
	ops->rrb = ops->rrb + 1;
	if (!ops->silent)
		ft_printf("rrb\n");
}

void	op_rrr(t_stack **a, t_stack **b, t_ops *ops)
{
	do_rrotate(a);
	do_rrotate(b);
	ops->rrr = ops->rrr + 1;
	if (!ops->silent)
		ft_printf("rrr\n");
}
