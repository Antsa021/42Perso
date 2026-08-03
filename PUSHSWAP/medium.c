/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isendris <isendris@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 00:00:00 by isendris          #+#    #+#             */
/*   Updated: 2026/07/25 20:04:17 by isendris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_b_to_top(t_stack **b, int pos, int size, t_ops *ops)
{
	int	moves;

	if (pos <= size / 2)
	{
		moves = 0;
		while (moves < pos)
		{
			op_rb(b, ops);
			moves = moves + 1;
		}
	}
	else
	{
		moves = size - pos;
		while (moves > 0)
		{
			op_rrb(b, ops);
			moves = moves - 1;
		}
	}
}

static int	pos_insertion(t_stack *b, int val)
{
	int	pos;
	int	best;
	int	best_pos;

	pos = 0;
	best = 0;
	best_pos = -1;
	while (b)
	{
		if (b->contenu < val && (best_pos < 0 || b->contenu > best))
		{
			best = b->contenu;
			best_pos = pos;
		}
		b = b->next;
		pos = pos + 1;
	}
	return (best_pos);
}

static void	deplacer_le_groupe(t_stack **a, t_stack **b, t_medium
*chantier, t_ops *ops)
{
	int	pushed;
	int	pos;
	int	size;

	pushed = 0;
	while (pushed < chantier->rank_max - chantier->rank_min && *a)
	{
		size = stack_size(*a);
		pos = cheapest_deplacement(*a, chantier, size);
		rotate_to_top(a, pos, size, ops);
		if (*b)
		{
			pos = pos_insertion(*b, (*a)->contenu);
			if (pos < 0)
				pos = find_max_pos(*b);
			rotate_b_to_top(b, pos, stack_size(*b), ops);
		}
		op_pb(a, b, ops);
		pushed = pushed + 1;
	}
}

static void	tri_final(t_stack **a, t_stack **b, t_ops *ops)
{
	if (*b)
		rotate_b_to_top(b, find_max_pos(*b), stack_size(*b), ops);
	while (*b)
		op_pa(a, b, ops);
}

void	sort_medium(t_stack **a, t_stack **b, t_ops *ops)
{
	t_medium	chantier;
	int			taille_groupe;

	chantier.n = stack_size(*a);
	taille_groupe = 1;
	while (taille_groupe * taille_groupe < chantier.n)
		taille_groupe++;
	chantier.sorted = build_ranktab(*a, chantier.n);
	chantier.rank_min = 0;
	while (chantier.rank_min < chantier.n)
	{
		chantier.rank_max = chantier.rank_min + taille_groupe;
		deplacer_le_groupe(a, b, &chantier, ops);
		chantier.rank_min = chantier.rank_min + taille_groupe;
	}
	free(chantier.sorted);
	tri_final(a, b, ops);
}
