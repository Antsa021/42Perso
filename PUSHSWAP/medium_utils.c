/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isendris <isendris@learner.tech.42>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 00:00:00 by isendris          #+#    #+#             */
/*   Updated: 2026/07/11 00:00:00 by isendris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_ranktab(int *arr, int n)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < n - 1)
	{
		j = i + 1;
		while (j < n)
		{
			if (arr[j] < arr[i])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j = j + 1;
		}
		i = i + 1;
	}
}

int	*build_ranktab(t_stack *a, int n)
{
	int		*arr;
	t_stack	*node;
	int		i;

	arr = malloc(n * sizeof(int));
	if (!arr)
		error_time(a);
	i = 0;
	node = a;
	while (node)
	{
		arr[i] = node->contenu;
		i = i + 1;
		node = node->next;
	}
	sort_ranktab(arr, n);
	return (arr);
}

int	trouvons_le_rank(int *sorted, int n, int val)
{
	int	lo;
	int	hi;
	int	mid;

	lo = 0;
	hi = n - 1;
	while (lo <= hi)
	{
		mid = (lo + hi) / 2;
		if (sorted[mid] == val)
			return (mid);
		if (sorted[mid] < val)
			lo = mid + 1;
		else
			hi = mid - 1;
	}
	return (0);
}

int	cheapest_deplacement(t_stack *a, t_medium *chantier, int size)
{
	int	pos;
	int	best;
	int	rank;

	pos = 0;
	best = -1;
	while (a)
	{
		rank = trouvons_le_rank(chantier->sorted, chantier->n, a->contenu);
		if (rank >= chantier->rank_min && rank < chantier->rank_max)
		{
			if (best < 0 || reach(pos, size) < reach(best, size))
				best = pos;
		}
		a = a->next;
		pos = pos + 1;
	}
	if (best < 0)
		return (0);
	return (best);
}

int	find_max_pos(t_stack *b)
{
	int	max;
	int	pos;
	int	cur;

	max = b->contenu;
	pos = 0;
	cur = 0;
	while (b->next)
	{
		b = b->next;
		cur = cur + 1;
		if (b->contenu > max)
		{
			max = b->contenu;
			pos = cur;
		}
	}
	return (pos);
}
