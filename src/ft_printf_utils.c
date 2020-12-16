/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 13:15:48 by ckurt             #+#    #+#             */
/*   Updated: 2020/12/16 17:52:30 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	init_struct(s_element *elem)
{
	elem->zero = 0;
	elem->width = 0;
	elem->field = 0;
	elem->left_justify = 0;
	elem->period = 0;
	elem->sign = 0;
	elem->type = 0;
}

int	print_width(int width, int has_zero)
{
	int		i;
	char	c;

	c = ' ';
	if (has_zero)
		c = '0';
	i = 0;
	while (i < width)
	{
		ft_putchar(c);
		i++;
	}
	return (i);
}