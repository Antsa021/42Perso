/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senandri <senandri@learner.tech.42>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 13:04:35 by senandri          #+#    #+#             */
/*   Updated: 2026/05/06 12:14:44 by senandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_rooh1(va_list *ap)
{
	char	*str;

	str = va_arg(*ap, char *);
	if (!str)
		return (ft_putstr_count("(null)"));
	return (ft_putstr_count(str));
}

static int	ft_rooh2(va_list *ap)
{
	void	*ptr;

	ptr = va_arg(*ap, void *);
	if (!ptr)
		return (ft_putstr_count("(nil)"));
	return (ft_putstr_count("0x") + ft_convhexa((unsigned long)ptr,
			"0123456789abcdef"));
}

static int	ft_cestquoi(char o_o, va_list *ap)
{
	if (o_o == 'c')
		return (ft_putchar_count((char)va_arg(*ap, int)));
	else if (o_o == 's')
		return (ft_rooh1(ap));
	else if (o_o == 'p')
		return (ft_rooh2(ap));
	else if (o_o == 'd' || o_o == 'i')
		return (ft_putnbr_count(va_arg(*ap, int)));
	else if (o_o == 'u')
		return (ft_putnbr_unsigned(va_arg(*ap, unsigned int)));
	else if (o_o == 'x')
		return (ft_convhexa((unsigned long)va_arg(*ap, unsigned int),
				"0123456789abcdef"));
	else if (o_o == 'X')
		return (ft_convhexa((unsigned long)va_arg(*ap, unsigned int),
				"0123456789ABCDEF"));
	else if (o_o == '%')
		return (ft_putchar_count('%'));
	return (0);
}

int	ft_printf(const char *o_o, ...)
{
	int		i;
	int		compteur;
	va_list	ap;

	va_start(ap, o_o);
	i = 0;
	compteur = 0;
	while (o_o[i])
	{
		if (o_o[i] != '%')
		{
			compteur = compteur + ft_putchar_count(o_o[i]);
			i++;
		}
		else
		{
			i++;
			compteur = compteur + ft_cestquoi(o_o[i], &ap);
			i++;
		}
	}
	va_end(ap);
	return (compteur);
}
