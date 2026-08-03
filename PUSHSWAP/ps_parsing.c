/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senandri <senandri@learner.tech.42>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 14:23:23 by senandri          #+#    #+#             */
/*   Updated: 2026/07/11 23:04:01 by senandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	quels_flags(const char *arg, t_flags *flags, t_stack *a)
{
	if (ft_strncmp(arg, "--simple", 9) == 0)
		flags->simple = 1;
	else if (ft_strncmp(arg, "--medium", 9) == 0)
		flags->medium = 1;
	else if (ft_strncmp(arg, "--complex", 10) == 0)
		flags->complex = 1;
	else if (ft_strncmp(arg, "--adaptive", 11) == 0)
		flags->adaptive = 1;
	else if (ft_strncmp(arg, "--bench", 8) == 0)
		flags->bench = 1;
	else if (ft_strncmp(arg, "--count-only", 13) == 0)
		flags->count_only = 1;
	else
		error_time(a);
}

static int	quel_sign(const char *str, int *i)
{
	int	sign;

	sign = 1;
	if (str[*i] == '-')
		sign = -1;
	if (str[*i] == '-' || str[*i] == '+')
		(*i)++;
	return (sign);
}

static int	on_transforme_en_ints(const char *str, int *output)
{
	long	val;
	int		sign;
	int		i;

	i = 0;
	val = 0;
	sign = quel_sign(str, &i);
	if (!ft_isdigit(str[i]))
		return (0);
	while (str[i] && str[i] != ' ')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		val = val * 10 + (str[i] - '0');
		if (val * sign > INT_MAX || val * sign < INT_MIN)
			return (0);
		i++;
	}
	*output = (int)(val * sign);
	return (i);
}

static t_stack	*plein_de_nombres(t_stack *a, const char *str)
{
	int	valeur;
	int	len;
	int	seen;

	seen = 0;
	while (*str)
	{
		while (*str == ' ')
			str++;
		if (!*str)
			break ;
		len = on_transforme_en_ints(str, &valeur);
		if (len == 0 || has_dup(a, valeur))
			error_time(a);
		a = stack_add_back(a, valeur);
		str += len;
		seen = 1;
	}
	if (!seen)
		error_time(a);
	return (a);
}

t_stack	*parse_args(int argc, char **argv, t_flags *flags)
{
	t_stack	*a;
	int		i;

	a = NULL;
	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
			quels_flags(argv[i], flags, a);
		else
			a = plein_de_nombres(a, argv[i]);
		i++;
	}
	return (a);
}
