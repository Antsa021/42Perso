/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isendris <isendris@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 00:00:00 by isendris          #+#    #+#             */
/*   Updated: 2026/07/25 18:48:37 by isendris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	print_count(t_ops *ops)
{
	int	total;

	total = ops->sa + ops->sb + ops->ss + ops->pa + ops->pb;
	total = total + ops->ra + ops->rb + ops->rr;
	total = total + ops->rra + ops->rrb + ops->rrr;
	ft_putnbr_fd(total, 1);
	ft_putchar_fd('\n', 1);
}

static int	quel_strat(t_flags *flags, t_stack *a, double disorder)
{
	if (flags->simple)
		return (STRAT_SIMPLE);
	if (flags->medium)
		return (STRAT_MEDIUM);
	if (flags->complex)
		return (STRAT_COMPLEX);
	return (quelle_strategie(stack_size(a), disorder));
}

static void	run(t_stack **a, t_stack **b, t_flags *flags, t_ops *ops)
{
	double	disorder;
	int		strat;

	error_flags(flags, *a);
	ops->silent = flags->count_only;
	disorder = compute_disorder(*a);
	strat = quel_strat(flags, *a, disorder);
	if (!is_sorted(*a))
	{
		if (strat == STRAT_SIMPLE)
			sort_simple(a, b, ops);
		else if (strat == STRAT_MEDIUM)
			sort_medium(a, b, ops);
		else
			sort_complex(a, b, ops);
	}
	if(flags->count_only)
		print_count(ops);
	if (flags->bench)
		print_bench(flags, disorder, ops, strat);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_flags	flags;
	t_ops	ops;

	ft_bzero(&flags, sizeof(t_flags));
	ft_bzero(&ops, sizeof(t_ops));
	b = NULL;
	a = parse_args(argc, argv, &flags);
	if (!a)
		return (0);
	run(&a, &b, &flags, &ops);
	free_stack(a);
	free_stack(b);
	return (0);
}
