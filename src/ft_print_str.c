/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 14:57:40 by ckurt             #+#    #+#             */
/*   Updated: 2021/01/04 13:26:57 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	int	print_justify(t_element *elem, char *str, int len)
{
	int		i;

	i = 0;
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
	return (i);
}

static	int	print_else(t_element *elem, char *str, int len)
{
	int		i;

	i = 0;
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
	return (i);
}

int			ft_print_str(t_element *elem, char *str)
{
	int		i;
	int		len;

	i = 0;
	if (str)
		len = ft_strlen(str);
	if (str == NULL)
	{
		free(str);
		str = ft_strdup("(null)");
		len = ft_strlen(str);
	}
	if (elem->left_justify && !elem->zero)
		i += print_justify(elem, str, len);
	else
		i += print_else(elem, str, len);
	free(str);
	return (i);
}
