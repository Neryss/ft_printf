/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 13:27:31 by ckurt             #+#    #+#             */
/*   Updated: 2020/12/25 14:09:04 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	int	print_di_else_minus(t_element *elem, char *str, int len)
{
	int		i;

	i = 0;
	if (elem->dot)
	{
		if (elem->dot_size > len)
		{
			i += print_width(elem, elem->dot_size);
			i += print_zero(elem->dot_size - len);
			i += ft_putstrl(str, len);
		}
		else
		{
			if (len == 1 && str[1] == 0)
			{
				i += print_width(elem, elem->dot_size);
				i += ft_putstrl(str, elem->dot_size);
			}
			else
			{
				i += print_width(elem, len);
				i += ft_putstr(str);
			}
		}
	}
	else
	{
		i += print_width(elem, len);
		i += ft_putstr(str);
	}
	return (i);
}