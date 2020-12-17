/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 12:59:40 by ckurt             #+#    #+#             */
/*   Updated: 2020/12/17 10:47:49 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	check_flags(const char *str, s_element *elem, va_list valist)
{
	int i;
	(void)valist;
	i = 0;
	str++;
	if (*str == '-')
	{
		elem->left_justify = 1;
		i++;
		str++;
	}
	if (ft_isdigit(*str))
	{
		if (*str == '0')
		{
			elem->zero = 1;
			i++;
		}
		elem->width = ft_atoi(str);
		i += ft_nblen(ft_atoi(str)) + 1;
	}
	return (i);
}

int	ft_parse_char(const char *str, s_element *elem, va_list valist)
{
	int	i;

	i = 0;
	(void)str;
	if (elem->left_justify == 1)
	{
		ft_putchar(va_arg(valist, int));
		print_width(elem->width - 1, elem->zero, elem->left_justify);
	}
	else
	{
		print_width(elem->width - 1, elem->zero, elem->left_justify);
		ft_putchar(va_arg(valist, int));
	}
	i++;
	return (i);
}