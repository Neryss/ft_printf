/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 13:15:48 by ckurt             #+#    #+#             */
/*   Updated: 2020/12/29 15:48:56 by ckurt            ###   ########lyon.fr   */
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

	i = 1;
	check_minus(str + 1, elem);
	check_zero(str + 1, elem);
	check_star(str + 1, elem, valist);
	if (!elem->dot)
		elem->dot_size = check_dot(str + 1, elem);
	if (!elem->width)
		elem->width = special_atoi(str + 1);
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
	return (i + 1);
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
