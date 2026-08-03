/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senandri <senandri@learner.tech.42>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 14:23:23 by senandri          #+#    #+#             */
/*   Updated: 2026/07/11 21:21:45 by senandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	on_swap(t_stack **s)
{
	int	temp;

	if (!*s || !(*s)->next)
		return ;
	temp = (*s)->contenu;
	(*s)->contenu = (*s)->next->contenu;
	(*s)->next->contenu = temp;
}

void	op_sa(t_stack **a, t_ops *ops)
{
	on_swap(a);
	ops->sa = ops->sa + 1;
	if (!ops->silent)
		ft_printf("sa\n");
}

void	op_sb(t_stack **b, t_ops *ops)
{
	on_swap(b);
	ops->sb = ops->sb + 1;
	if (!ops->silent)
		ft_printf("sb\n");
}

void	op_ss(t_stack **a, t_stack **b, t_ops *ops)
{
	on_swap(a);
	on_swap(b);
	ops->ss = ops->ss + 1;
	if (!ops->silent)
		ft_printf("ss\n");
}
