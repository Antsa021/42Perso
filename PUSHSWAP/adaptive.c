/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isendris <isendris@learner.tech.42>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 00:00:00 by isendris          #+#    #+#             */
/*   Updated: 2026/07/25 01:48:26 by isendris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	count_inversions(t_stack *a)
{
	t_stack	*i;
	t_stack	*j;
	long	mistakes;

	mistakes = 0;
	i = a;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->contenu > j->contenu)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	return (mistakes);
}

double	compute_disorder(t_stack *a)
{
	long	total;

	if (!a || !a->next)
		return (0.0);
	total = (long)stack_size(a);
	total = total * (total - 1) / 2;
	return ((double)count_inversions(a) / (double)total);
}

int	quelle_strategie(int n, double disorder)
{
	if (n <= 5)
		return (STRAT_SIMPLE);
	if (disorder >= 0.5 || n >= 360)
		return (STRAT_COMPLEX);
	if (disorder < 0.2)
		return (STRAT_SIMPLE);
	return (STRAT_MEDIUM);
}
