/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 13:02:03 by ckurt             #+#    #+#             */
/*   Updated: 2020/12/17 14:45:37 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int parse_str(va_list valist, const char *str, s_element *elem)
{
	while (*str)
	{
		if (*str == '%')
		{
			init_struct(elem);
			str += check_flags(str, elem);
			str += select_parsing(valist, str, elem);
		}

		ft_putchar(*str++);
	}
	return (0);
}

int	select_parsing(va_list valist, const char *str, s_element *elem)
{
	int i;

	i = 0;
	// debug_struct(elem);
	if (*str == 'c')
	{
		i = ft_parse_char(str, elem, valist);
		return (i);
	}
	return (0);
}

int ft_printf(const char *str, ...)
{
	va_list args;
	s_element elem;

	init_struct(&elem);
	va_start(args, str);
	parse_str(args, str, &elem);
	va_end(args);
	return (1);
}
