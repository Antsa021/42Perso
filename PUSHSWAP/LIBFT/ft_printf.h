/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senandri <senandri@learner.tech.42>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 10:45:07 by senandri          #+#    #+#             */
/*   Updated: 2026/05/06 12:06:58 by senandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

int	ft_printf(const char *o_o, ...);
int	ft_convhexa(unsigned long n, char *base);
int	ft_putchar_count(char c);
int	ft_putstr_count(char *s);
int	ft_putnbr_count(int n);
int	ft_putnbr_unsigned(unsigned int n);

#endif
