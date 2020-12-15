/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 13:02:03 by ckurt             #+#    #+#             */
/*   Updated: 2020/12/15 17:33:34 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	get_arg(va_list valist, const char *str)
{
	str++;
	if (*str == 'c')
		ft_putchar(va_arg(valist, int));
	if (*str == 's')
		ft_putstr(va_arg(valist, char *));
	if (*str == 'i' || *str == 'd')
		ft_putnbr(va_arg(valist, int));
	// if (*str == 'x' || *str == 'X')
	return (1);
}

size_t	get_wlen(const char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '%')
		i++;
	return (i);
}

int	parse_str(va_list valist, const char *str)
{
	while (*str)
	{
		if (*str == '%')
			get_arg(valist, str);
		str++;
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list args;
	// char	*buff;

	va_start(args, str);
	parse_str(args, str);
	va_end(args);
	return (1);
}
