/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isendris <isendris@learner.tech.42>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 00:00:00 by isendris          #+#    #+#             */
/*   Updated: 2026/07/25 01:20:56 by isendris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	passe_du_bit(t_stack **a, t_stack **b,
		t_complex *chantier, t_ops *ops)
{
	int	i;
	int	rank;

	i = 0;
	while (i < chantier->n)
	{
		rank = trouvons_le_rank(chantier->sorted, chantier->n, (*a)->contenu);
		if ((rank / chantier->poids) % 2 == 1)
			op_ra(a, ops);
		else
			op_pb(a, b, ops);
		i++;
	}
	while (*b)
		op_pa(a, b, ops);
}

void	sort_complex(t_stack **a, t_stack **b, t_ops *ops)
{
	t_complex	chantier;

	chantier.n = stack_size(*a);
	chantier.sorted = build_ranktab(*a, chantier.n);
	chantier.poids = 1;
	while (chantier.poids < chantier.n)
	{
		passe_du_bit(a, b, &chantier, ops);
		chantier.poids = chantier.poids * 2;
	}
	free(chantier.sorted);
}
