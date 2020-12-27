/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 13:14:54 by ckurt             #+#    #+#             */
/*   Updated: 2020/12/27 13:19:28 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_percent(t_element *elem)
{
	int	i;

	i = 0;
	printf("yes");
	if (elem->left_justify)
	{
		i += ft_putchar('%');
		i += print_width(elem, 1);
	}
	else
	{
		i += print_width(elem, 1);
		i += ft_putchar('%');
	}
	return (i);
}