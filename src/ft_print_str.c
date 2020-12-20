/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 14:57:40 by ckurt             #+#    #+#             */
/*   Updated: 2020/12/20 22:13:22 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_print_str(s_element *elem, char *str)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(str);
	if (str == NULL)
	{
		i += ft_putstr("(null)");
		return (i);
	}
	if (elem->left_justify == 1)
	{
		if (elem->dot)
		{
			if (elem->dot_size > len)
				elem->dot_size = len;
			i += ft_putstrl(str, elem->dot_size);
			i += print_width(elem, elem->dot_size);
		}
		else
		{
			i += ft_putstr(str);
			i += print_width(elem, len);
		}
	}
	else
	{
		if (elem->dot)
		{
			if (elem->dot_size > len)
				elem->dot_size = len;
			i += print_width(elem, elem->dot_size);
			i += ft_putstrl(str, elem->dot_size);
		}
		else
		{
			i += print_width(elem, len);
			i += ft_putstr(str);
		}
	}
	return (i);
}