/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 13:27:31 by ckurt             #+#    #+#             */
/*   Updated: 2020/12/29 15:40:42 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	dot_else_justif(t_element *elem, char *str, int len)
{
	int		i;

	i = 0;
	if (len == 1 && str[0] == '0')
	{
		i += ft_putstrl(str, elem->dot_size);
		i += print_width(elem, elem->dot_size);
	}
	else
	{
		i += ft_putstr(str);
		i += print_width(elem, len);
	}
	return (i);
}

int	dot_size_greater_justif(t_element *elem, char *str, int len)
{
	int		i;

	i = 0;
	if (str[0] == '-')
	{
		i += ft_putchar('-');
		i += print_zero(elem->dot_size - len + 1);
		i += ft_putstrl(str + 1, elem->dot_size);
		i += print_width(elem, elem->dot_size + 1);
	}
	else
	{
		i += print_zero(elem->dot_size - len);
		i += ft_putstr(str);
		i += print_width(elem, elem->dot_size);
	}
	return (i);
}

int	is_zero_dielse(t_element *elem, char *str, int len)
{
	int i;

	i = 0;
	if (elem->zero)
	{
		i += ft_putchar('-');
		i += print_width(elem, len);
		i += ft_putstr(str + 1);
	}
	else
	{
		i += print_width(elem, len);
		i += ft_putchar('-');
		i += ft_putstr(str + 1);
	}
	return (i);
}
