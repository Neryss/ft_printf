/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 12:59:40 by ckurt             #+#    #+#             */
/*   Updated: 2020/12/17 15:36:04 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	is_minus_in_str(const char *str, s_element *elem, int i)
{
	while (str[i])
	{
		if (str[i] == '-')
		{
			elem->left_justify = 1;
			return (i);
		}
		i++;
	}
	return (0);
}

int	check_flags(const char *str, s_element *elem)
{
	int i;
	int	minus;

	i = 0;
	str++;
	if (check_minus(*str, elem))
	{
		str++;
		i++;
	}
	if (ft_isdigit(*str))
	{
		if (*str == '0')
		{
			elem->zero = 1;
			i++;
		}
		minus = is_minus_in_str(str, elem, i);
		i += minus;
		elem->width = get_minus_len(str, i);
		// if (check_minus(str[i], elem))
		// 	elem->width = get_minus_len(str, i);
		// elem->width = get_minus_len(str, i - 1);
		i += get_elem_len(str, i);
		i++;
		// printf("i is %d", i);
		// printf("str (%c)\n", str[i]);
	}
	if (i == 0)
		return (1);
	return (i);
}

int	ft_parse_char(const char *str, s_element *elem, va_list valist)
{
	int	i;

	i = 0;
	(void)str;
	if (elem->left_justify == 1)
	{
		// printf("justified\n");
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