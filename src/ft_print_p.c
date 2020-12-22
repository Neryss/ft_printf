/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 12:21:16 by ckurt             #+#    #+#             */
/*   Updated: 2020/12/22 09:31:30 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

// int print_p_width(s_element *elem, int len, char *str)
// {
// 	int i;

// 	i = 0;
// 	i += print_width(elem, len + 2);
// 	i += ft_putstr("0x");
// 	i += ft_putstr(str);
// 	return (i);
// }
static	int	print_p_zero(int len)
{
	int i;

	i = 0;
	while (i < len)
		i += ft_putchar('0');
	return (i);
}

static int print_p_justify(s_element *elem, char *str, int len)
{
	int i;

	i = 0;
	if (elem->dot)
	{
		if (elem->dot_size > len)
		{
			elem->zero = 1;
			i += ft_putstr("0x");
			i += ft_putstrl(str, elem->dot_size);
			i += print_p_zero(elem->dot_size - len);
		}
		else
		{
			i += ft_putstr("0x");
			i += ft_putstrl(str, elem->dot_size);
			i += print_width(elem, elem->dot_size);
		}
	}
	else
	{
		i += ft_putstr("0x");
		i += ft_putstrl(str, len);
		i += print_width(elem, len + 2);
	}
	return (i);
}


static	int	print_p_else(s_element *elem, char *str, int len)
{
	int i;

	i = 0;
	if (elem->dot)
	{
		if (elem->dot_size > len)
		{
			elem->zero = 0;
			i += print_width(elem, elem->dot_size + 2);
			elem->zero = 1;
			i += ft_putstr("0x");
			i += print_p_zero(elem->dot_size - len);
			i += ft_putstrl(str, elem->dot_size);
		}
		else
		{
			i += print_width(elem, elem->dot_size);
			i += ft_putstr("0x");
			i += ft_putstr(str);
		}
	}
	else
	{
		i += ft_putstr("0x");
		i += print_width(elem, len + 2);
		i += ft_putstrl(str, len);
	}
	return (i);
}

int ft_print_p(s_element *elem, size_t nb)
{
	int i;
	int len;
	char *str;

	i = 0;
	str = ft_itoa_base(nb, "0123456789abcdef");
	len = ft_strlen(str);
	if (elem->left_justify)
		i += print_p_justify(elem, str, len);
	else
		i += print_p_else(elem, str, len);
	return (i);
}