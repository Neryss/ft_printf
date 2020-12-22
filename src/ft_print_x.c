/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 10:22:52 by ckurt             #+#    #+#             */
/*   Updated: 2020/12/22 11:02:28 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	int	zero_else_x(t_element *elem, char *str, int len)
{
	int		i;

	i = 0;
	if (elem->dot_size > len)
	{
		elem->zero = 0;
		i += print_width(elem, elem->dot_size);
		elem->zero = 1;
		i += print_zero(elem->dot_size - len);
		i += ft_putstr(str);
	}
	else
	{
		i += print_width(elem, elem->dot_size);
		i += ft_putstr(str);
	}
	return (i);
}

static	int	print_x_else(t_element *elem, char *str, int len)
{
	int i;

	i = 0;
	if (elem->dot)
		i += zero_else_x(elem, str, len);
	else
	{
		i += print_width(elem, len);
		i += ft_putstr(str);
	}
	return (i);
}

int	ft_print_x(t_element *elem, int nb, char *base)
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	str = ft_itoa_base(nb, base);
	len = ft_strlen(str);
	if (elem->left_justify)
	{
		i += ft_putstr(str);
		i += print_width(elem, len);
	}
	else
		i += print_x_else(elem, str, len);
	return (i);
}