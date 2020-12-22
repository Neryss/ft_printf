/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 10:22:52 by ckurt             #+#    #+#             */
/*   Updated: 2020/12/22 19:11:29 by ckurt            ###   ########lyon.fr   */
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
		i += ft_putstrl(str, elem->dot_size);
	}
	else
	{
		i += print_width(elem, elem->dot_size);
		i += ft_putstrl(str, elem->dot_size);
	}
	return (i);
}

static	int	zero_justify_x(t_element *elem, char *str, int len)
{
	int		i;

	i = 0;
	if (elem->dot_size > len)
	{
		i += print_zero(elem->dot_size - len);
		elem->zero = 0;
		i += ft_putstr(str);
		i += print_width(elem, elem->dot_size);
	}
	else
	{
		i += ft_putstr(str);
		i += print_width(elem, len);
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
		i += ft_putstrl(str, len);
	}
	return (i);
}

static	int	print_x_justify(t_element *elem, char *str, int len)
{
	int i;

	i = 0;
	if (elem->dot)
		i += zero_justify_x(elem, str, len);
	else
	{
		i += ft_putstr(str);
		i += print_width(elem, len);
	}
	return (i);
}

int	ft_print_x(t_element *elem, unsigned int nb, char *base)
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	str = ft_itoa_base(nb, base);
	len = ft_strlen(str);
	if (elem->left_justify)
		i += print_x_justify(elem, str, len);
	else
		i += print_x_else(elem, str, len);
	str = NULL;
	free(str);
	return (i);
}