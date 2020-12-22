/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 13:15:48 by ckurt             #+#    #+#             */
/*   Updated: 2020/12/22 12:52:04 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		init_struct(t_element *elem)
{
	elem->zero = 0;
	elem->width = 0;
	elem->field = 0;
	elem->left_justify = 0;
	elem->dot = 0;
	elem->dot_size = 0;
	elem->sign = 0;
	elem->type = 0;
	elem->star = 0;
}

void		debug_struct(t_element *elem)
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
	ft_putstr("|\n|Dot size: ");
	ft_putnbr(elem->dot_size);
	ft_putstr("|\n|Sign : ");
	ft_putnbr(elem->sign);
	ft_putstr("|\n|Type : ");
	ft_putchar(elem->type);
	ft_putstr("|\n|Star : ");
	ft_putnbr(elem->star);
	ft_putstr("|\n| ------ |");
	ft_putstr("\n| END |\n\n");
}

int			check_dot(const char *str, t_element *elem)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	while (str[i] && !ft_ischarset(str[i], ARGUMENTS))
	{
		if (str[i] == '.')
		{
			i++;
			elem->dot = 1;
			while (ft_isdigit(str[i]))
			{
				res = res * 10 + (str[i] - 48);
				i++;
			}
			return (res);
		}
		i++;
	}
	return (res);
}

int			check_flags(const char *str, t_element *elem, va_list valist)
{
	int		i;

	i = 0;
	check_minus(str, elem);
	check_zero(str, elem);
	check_star(str, elem, valist);
	if (!elem->dot_size)
		elem->dot_size = check_dot(str, elem);
	// if (elem->star)
	// {
	// 	if (is_dot_first(str))
	// 		elem->dot_size = va_arg(valist, int);
	// 	else
	// 		elem->width = va_arg(valist, int);
	// }
	if (!elem->star)
		elem->width = special_atoi(str);
	if (elem->width < 0)
	{
		if (elem->width < 0)
			elem->width = -elem->width;
		elem->left_justify = 1;
	}
	if (elem->dot_size < 0)
		elem->dot = 0;
	i = get_memberlen(str, elem, i);
	if (i == 0)
		return (1);
	return (i);
}

int			get_memberlen(const char *str, t_element *elem, int i)
{
	while (!ft_ischarset(str[i], ARGUMENTS) && str[i])
		i++;
	elem->type = str[i];
	return (i);
}

int			print_width(t_element *elem, int len)
{
	int		i;
	char	c;

	c = ' ';
	if (elem->zero && !elem->left_justify)
		c = '0';
	i = 0;
	while (i < elem->width - len)
	{
		ft_putchar(c);
		i++;
	}
	return (i);
}
