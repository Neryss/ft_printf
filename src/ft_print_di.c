/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 18:48:52 by ckurt             #+#    #+#             */
/*   Updated: 2021/01/04 12:16:13 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	int	dot_size_greater_else(t_element *elem, char *str, int len)
{
	int		i;

	i = 0;
	elem->zero = 0;
	if (str[0] == '-')
	{
		i += print_width(elem, elem->dot_size + 1);
		i += ft_putchar('-');
		i += print_zero(elem->dot_size - len + 1);
		i += ft_putstrl(str + 1, len);
	}
	else
	{
		i += print_width(elem, elem->dot_size);
		i += print_zero(elem->dot_size - len);
		i += ft_putstrl(str, len);
	}
	return (i);
}

static	int	print_dot_else(t_element *elem, char *str, int len)
{
	int		i;

	i = 0;
	if (elem->dot_size >= len)
		i += dot_size_greater_else(elem, str, len);
	else
	{
		elem->zero = 0;
		if (len == 1 && str[0] == '0')
		{
			i += print_width(elem, elem->dot_size);
			i += ft_putstrl(str, elem->dot_size);
		}
		else
		{
			elem->zero = 0;
			i += print_width(elem, len);
			i += ft_putstr(str);
		}
	}
	return (i);
}

static	int	print_di_else(t_element *elem, char *str, int len)
{
	int		i;

	i = 0;
	if (elem->dot)
		i += print_dot_else(elem, str, len);
	else
	{
		if (str[0] == '-')
			i += is_zero_dielse(elem, str, len);
		else
		{
			i += print_width(elem, len);
			i += ft_putstr(str);
		}
	}
	return (i);
}

static	int	print_di_justify(t_element *elem, char *str, int len)
{
	int		i;

	i = 0;
	if (elem->dot)
	{
		if (elem->dot_size >= len)
			i += dot_size_greater_justif(elem, str, len);
		else
			i += dot_else_justif(elem, str, len);
	}
	else
	{
		if (str[0] == '-')
		{
			i += ft_putchar('-');
			i += ft_putstr(str + 1);
			i += print_width(elem, len);
		}
		else
		{
			i += ft_putstr(str);
			i += print_width(elem, len);
		}
	}
	return (i);
}

int			ft_print_di(t_element *elem, int nb)
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	str = ft_itoa(nb);
	len = ft_strlen(str);
	if (elem->left_justify)
		i += print_di_justify(elem, str, len);
	else
		i += print_di_else(elem, str, len);
	free(str);
	return (i);
}
