/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 19:59:20 by ckurt             #+#    #+#             */
/*   Updated: 2020/12/26 22:36:45 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	int	print_u_justif(t_element *elem, char *str, int len)
{
	int		i;

	i = 0;
	if (elem->dot)
	{
		if (elem->dot_size > len)
		{
			i += ft_putstr(str);
			i += print_zero(elem->dot_size - len);
			i += print_width(elem, len + 1);
		}
		else
		{
			elem->zero = 1;
			i += ft_putstrl(str, elem->dot_size);
			i += print_width(elem, elem->dot_size);
		}
	}
	else
	{
		i += ft_putstr(str);
		i += print_width(elem, len);
	}
	return (i);
}

static	int	print_u_else(t_element *elem, char *str, int len)
{
	int		i;

	i = 0;
	if (elem->dot)
	{
		if (elem->dot_size > len)
		{
			i += print_zero(elem->dot_size - len);
			i += ft_putstr(str);
			i += print_width(elem, elem->dot_size);
		}
		else
		{
			elem->zero = 1;
			i += print_width(elem, elem->dot_size);
			i += ft_putstrl(str, elem->dot_size);
		}
	}
	else
	{
		i += print_width(elem, len);
		i += ft_putstr(str);
	}
	return (i);
}

int			ft_print_u(t_element *elem, unsigned int nb)
{
	char	*str;
	int		len;
	int		i;
	(void)elem;

	i = 0;
	str = ft_uitoa(nb);
	len = ft_strlen(str);
	if (elem->left_justify)
		i += print_u_justif(elem, str, len);
	else
		i += print_u_else(elem, str, len);
	return (i);
}