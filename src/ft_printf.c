/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 13:02:03 by ckurt             #+#    #+#             */
/*   Updated: 2020/12/21 16:02:23 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int general_parsing(va_list valist, const char *str, s_element *elem)
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
		return (ft_print_char(elem, valist));
	if (elem->type == 's')
		return (ft_print_str(elem, va_arg(valist, char *)));
	if (elem->type == 'p')
		return (ft_print_p(elem, va_arg(valist, size_t)));
	return (0);
}

int ft_printf(const char *str, ...)
{
	va_list		args;
	s_element	elem;
	int			print;

	init_struct(&elem);
	va_start(args, str);
	print = general_parsing(args, str, &elem);
	va_end(args);
	return (print);
}
