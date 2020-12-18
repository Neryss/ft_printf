/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 13:15:48 by ckurt             #+#    #+#             */
/*   Updated: 2020/12/18 09:48:15 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	init_struct(s_element *elem)
{
	elem->zero = 0;
	elem->width = 0;
	elem->field = 0;
	elem->left_justify = 0;
	elem->dot = 0;
	elem->sign = 0;
	elem->type = 0;
	elem->star = 0;
}

void	debug_struct(s_element *elem)
{
	ft_putstr("| ELEMENT |\n");
	ft_putstr("| ------- |\n");
	ft_putstr("|Zero : ");
	ft_putnbr(elem->zero);
	ft_putstr("|\n|Width : ");
	ft_putnbr(elem->width);
	ft_putstr("|\n|Field : ");
	ft_putnbr(elem->field);
	ft_putstr("|\n|Justify : ");
	ft_putnbr(elem->left_justify);
	ft_putstr("|\n|Dot : ");
	ft_putnbr(elem->dot);
	ft_putstr("|\n|Sign : ");
	ft_putnbr(elem->sign);
	ft_putstr("|\n|Type : ");
	ft_putnbr(elem->type);
	ft_putstr("|\n| ------ |");
	ft_putstr("\n| END |\n\n");
}

int			get_minus_len(const char *str, int i)
{
	int		res;

	res = 0;
	while (!ft_isdigit(str[i]))
		i++;
	while (ft_isdigit(str[i]))
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res);
}

int	get_elem_len(const char *str, int i)
{
	while (str[i])
	{
		if (str[i] == 'c')
			return (i);
		i++;
	}
	return (0);
}

int	print_width(s_element *elem)
{
	int		i;
	char	c;

	c = ' ';
	if (elem->zero && !elem->left_justify)
		c = '0';
	i = 0;
	while (i < elem->width - 1)
	{
		ft_putchar(c);
		i++;
	}
	return (i);
}