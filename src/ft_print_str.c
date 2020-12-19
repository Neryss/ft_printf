/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 14:57:40 by ckurt             #+#    #+#             */
/*   Updated: 2020/12/19 15:49:01 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_print_str(s_element *elem, char *str)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(str);
	if (elem->left_justify == 1)
	{
		i += ft_putstr(str);
		i += print_width(elem, len);
	}
	else
	{
		i += print_width(elem, len);
		i += ft_putstr(str);
	}
	return (i);
}