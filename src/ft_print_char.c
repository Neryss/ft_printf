/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 12:59:40 by ckurt             #+#    #+#             */
/*   Updated: 2020/12/19 16:37:25 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	special_atoi(const char *str)
{
	int i;
	int res;

	i = 0;
	res = 0;
	//might need to add whitespaces later
	//not sure about the '%'
	while (str[i] == '0' || str[i] == '-' || str[i] == '%')
		i++;
	while (ft_isdigit(str[i]))
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res);
}

int	ft_print_char(s_element *elem, va_list valist)
{
	int	i;

	i = 0;
	if (elem->left_justify == 1)
	{
		i += ft_putchar(va_arg(valist, int));
		i += print_width(elem, 1);
	}
	else
	{
		i += print_width(elem, 1);
		i += ft_putchar(va_arg(valist, int));
	}
	return (i);
}
