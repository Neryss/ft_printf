/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 12:59:40 by ckurt             #+#    #+#             */
/*   Updated: 2020/12/18 09:45:07 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	special_atoi(const char *str)
{
	int i;
	int res;

	i = 0;
	res = 0;
	//might need to add whitespaces later
	//not sure about the '%'
	while (str[i] == '0' || str[i] == '-' || str[i] == '%')
		i++;
	while (ft_isdigit(str[i]))
	{

		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res);
}

int	get_memberlen(const char *str, int i)
{
	while (!ft_ischarset(str[i], ARGUMENTS) && str[i])
		i++;
	return (i);
}

int	check_flags(const char *str, s_element *elem)
{
	int i;

	i = 0;
	check_minus(str, elem, i);
	check_zero(str, elem);
	check_star(str, elem);
	elem->width = special_atoi(str);
	i = get_memberlen(str, i);
	if (i == 0)
		return (1);
	return (i);
}

int	ft_parse_char(const char *str, s_element *elem, va_list valist)
{
	int	i;

	i = 0;
	(void)str;
	if (elem->left_justify == 1)
	{
		// printf("justified\n");
		ft_putchar(va_arg(valist, int));
		print_width(elem);
	}
	else
	{
		print_width(elem);
		ft_putchar(va_arg(valist, int));
	}
	i++;
	return (i);
}