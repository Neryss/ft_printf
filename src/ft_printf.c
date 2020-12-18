/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 13:02:03 by ckurt             #+#    #+#             */
/*   Updated: 2020/12/18 20:18:30 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int parse_str(va_list valist, const char *str, s_element *elem)
{
	int	print;

	print = 0;
	while (*str)
	{
		if (*str == '%')
		{
			init_struct(elem);
			str += check_flags(str, elem, valist) + 1;
			print += select_parsing(valist, elem);
		}
		else
		{
			ft_putchar(*str++);
			print++;
		}
	}
	return (print);
}

int	select_parsing(va_list valist, s_element *elem)
{
	int i;

	i = 0;
	// debug_struct(elem);
	if (elem->type == 'c')
		return (ft_parse_char(elem, valist));
	return (0);
}

int ft_printf(const char *str, ...)
{
	va_list		args;
	s_element	elem;
	int			print;

	init_struct(&elem);
	va_start(args, str);
	print = parse_str(args, str, &elem);
	va_end(args);
	return (print);
}
