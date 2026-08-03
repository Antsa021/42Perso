/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senandri <senandri@learner.tech.42>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 00:00:00 by senandri          #+#    #+#             */
/*   Updated: 2026/07/11 00:00:00 by senandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_disorder(double disorder)
{
	int	whole;
	int	decimal;

	whole = (int)(disorder * 100);
	decimal = (int)(disorder * 10000) % 100;
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd(whole, 2);
	ft_putchar_fd('.', 2);
	if (decimal < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd(decimal, 2);
	ft_putstr_fd("%\n", 2);
}

static void	print_strategy(t_flags *flags, int strat)
{
	ft_putstr_fd("[bench] strategy: ", 2);
	if (flags->simple)
		ft_putstr_fd("Simple / O(n^2)\n", 2);
	else if (flags->medium)
		ft_putstr_fd("Medium / O(n*sqrt(n))\n", 2);
	else if (flags->complex)
		ft_putstr_fd("Complex / O(n*log(n))\n", 2);
	else if (strat == STRAT_SIMPLE)
		ft_putstr_fd("Adaptive / O(n^2)\n", 2);
	else if (strat == STRAT_MEDIUM)
		ft_putstr_fd("Adaptive / O(n*sqrt(n))\n", 2);
	else
		ft_putstr_fd("Adaptive / O(n*log(n))\n", 2);
}

static void	print_swap_ops(t_ops *ops)
{
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putnbr_fd(ops->sa, 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(ops->sb, 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(ops->ss, 2);
	ft_putstr_fd(" pa: ", 2);
	ft_putnbr_fd(ops->pa, 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(ops->pb, 2);
	ft_putchar_fd('\n', 2);
}

static void	print_rotate_ops(t_ops *ops)
{
	ft_putstr_fd("[bench] ra: ", 2);
	ft_putnbr_fd(ops->ra, 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(ops->rb, 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(ops->rr, 2);
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(ops->rra, 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(ops->rrb, 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(ops->rrr, 2);
	ft_putchar_fd('\n', 2);
}

void	print_bench(t_flags *flags, double disorder, t_ops *ops, int strat)
{
	int	total;

	total = ops->sa + ops->sb + ops->ss + ops->pa + ops->pb;
	total = total + ops->ra + ops->rb + ops->rr;
	total = total + ops->rra + ops->rrb + ops->rrr;
	print_disorder(disorder);
	print_strategy(flags, strat);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(total, 2);
	ft_putchar_fd('\n', 2);
	print_swap_ops(ops);
	print_rotate_ops(ops);
}
