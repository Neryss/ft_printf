/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 09:35:29 by ckurt             #+#    #+#             */
/*   Updated: 2020/12/20 21:13:48 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	check_minus(const char *str, s_element *elem)
{
	int i;

	i = 0;
	while (str[i] && !ft_ischarset(str[i], ARGUMENTS))
	{
		if (str[i] == '-')
		{
			elem->left_justify = 1;
			return (i);
		}
		i++;
	}
	return (-1);
}

int	check_zero(const char *str, s_element *elem)
{
	int i;

	i = 0;
	while (!ft_isdigit(str[i]) && !ft_ischarset(str[i], ARGUMENTS))
		i++;
	if (str[i] == '0')
	{
		if (str[i - 1] == '.')
			return (0);
		elem->zero = 1;
		return (1);
	}
	return (0);
}

int	check_star(const char *str, s_element *elem)
{
	int i;

	i = 0;
	while (str[i] && !ft_ischarset(str[i], ARGUMENTS))
	{
		if (str[i] == '*')
		{
			elem->star = 1;
			return (i);
		}
		i++;
	}
	return (-1);
}
