/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senandri <senandri@learner.tech.42>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 14:23:23 by senandri          #+#    #+#             */
/*   Updated: 2026/07/25 18:21:23 by senandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_time(t_stack *a)
{
	free_stack(a);
	write(2, "Error\n", 6);
	exit(1);
}

void	error_flags(t_flags *flags, t_stack *a)
{
	int	count;

	count = flags->simple + flags->medium + flags->complex + flags->adaptive;
	if (count > 1)
		error_time(a);
}
