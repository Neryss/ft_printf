/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 12:59:40 by ckurt             #+#    #+#             */
/*   Updated: 2020/12/16 17:48:11 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	check_flags(const char *str, s_element *elem, va_list valist)
{
	int i;
	(void)valist;
	i = 0;
	str++;
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
	// str++;
	(void)str;
	// if (elem->width != 0)
		print_width(elem->width - 1, elem->zero);
	ft_putchar(va_arg(valist, int));
	i++;
	return (i);
}