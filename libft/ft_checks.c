/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliagarc <eliagarc@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:51:19 by eliagarc          #+#    #+#             */
/*   Updated: 2023/10/24 11:08:24 by eliagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	typ_check2(const char var, va_list vl)
{
	unsigned long	pm;

	if (var == 'p')
	{
		pm = (unsigned long)va_arg(vl, void *);
		return (ft_putnbrp(pm, 1));
	}
	else if (var == 'x')
	{
		g_i = va_arg(vl, unsigned int);
		return (ft_putnbr_hx(g_i, 1, 1));
	}
	else if (var == 'X')
	{
		g_i = va_arg(vl, unsigned int);
		return (ft_putnbr_hx(g_i, 1, 2));
	}
	else if (var == '%')
	{
		return (ft_putchar('%'));
	}
	return (0);
}

static int	typ_check(const char var, va_list vl)
{
	if (var == 'c')
	{
		g_c = (char)va_arg(vl, int);
		return (ft_putchar(g_c));
	}
	else if (var == 's')
	{
		g_s = va_arg(vl, char *);
		return (ft_putstr(g_s, 1));
	}
	else if (var == 'i' || var == 'd')
	{
		g_i = va_arg(vl, int);
		return (ft_putnbr(g_i, 1));
	}
	else if (var == 'u')
	{
		g_ui = va_arg(vl, unsigned int);
		return (ft_putnbru(g_ui, 1));
	}
	return (0);
}

int	check_format(char arg, va_list vl)
{
	int	aux;

	aux = typ_check(arg, vl);
	if (aux == -1)
		return (-1);
	if (!aux)
	{
		return (typ_check2(arg, vl));
	}
	return (aux);
}
