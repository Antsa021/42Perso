/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senandri <senandri@learner.tech.42>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 14:23:23 by senandri          #+#    #+#             */
/*   Updated: 2026/07/11 20:51:04 by senandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "LIBFT/libft.h"

# define STRAT_SIMPLE 1
# define STRAT_MEDIUM 2
# define STRAT_COMPLEX 3

typedef struct s_stack
{
	int				contenu;
	struct s_stack	*next;
}	t_stack;

typedef struct s_ops
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int silent;
}	t_ops;

typedef struct s_flags
{
	int	simple;
	int	medium;
	int	complex;
	int	adaptive;
	int	bench;
	int count_only;
}	t_flags;

typedef struct s_medium
{
	int	*sorted;
	int	n;
	int	rank_min;
	int	rank_max;
}	t_medium;

typedef struct s_complex
{
	int	*sorted;
	int	n;
	int	poids;
}	t_complex;

/* errors.c */
void	error_time(t_stack *a);
void	error_flags(t_flags *flags, t_stack *a);

/* stack.c */
int		has_dup(t_stack *a, int val);
t_stack	*stack_add_back(t_stack *head, int val);
int		stack_size(t_stack *a);
int		is_sorted(t_stack *a);
void	free_stack(t_stack *a);

/* op_swap.c */
void	op_sa(t_stack **a, t_ops *ops);
void	op_sb(t_stack **b, t_ops *ops);
void	op_ss(t_stack **a, t_stack **b, t_ops *ops);

/* op_push.c */
void	op_pa(t_stack **a, t_stack **b, t_ops *ops);
void	op_pb(t_stack **a, t_stack **b, t_ops *ops);

/* op_rotate.c */
void	op_ra(t_stack **a, t_ops *ops);
void	op_rb(t_stack **b, t_ops *ops);
void	op_rr(t_stack **a, t_stack **b, t_ops *ops);

/* op_rrotate.c */
void	op_rra(t_stack **a, t_ops *ops);
void	op_rrb(t_stack **b, t_ops *ops);
void	op_rrr(t_stack **a, t_stack **b, t_ops *ops);

/* simple.c */
void	sort_three(t_stack **a, t_ops *ops);
void	sort_simple(t_stack **a, t_stack **b, t_ops *ops);
void	rotate_to_top(t_stack **a, int pos, int size, t_ops *ops);
int		reach(int pos, int size);

/* medium_utils.c */
int		*build_ranktab(t_stack *a, int n);
int		trouvons_le_rank(int *sorted, int n, int val);
int		find_max_pos(t_stack *b);
int		cheapest_deplacement(t_stack *a, t_medium *chantier, int size);

/* medium.c */
void	sort_medium(t_stack **a, t_stack **b, t_ops *ops);

/* complex.c */
void	sort_complex(t_stack **a, t_stack **b, t_ops *ops);

/* adaptive.c */
double	compute_disorder(t_stack *a);
int		quelle_strategie(int n, double disorder);

/* bench.c */
void	print_bench(t_flags *flags, double disorder, t_ops *ops, int strat);

/* parsing.c */
t_stack	*parse_args(int argc, char **argv, t_flags *flags);

#endif
