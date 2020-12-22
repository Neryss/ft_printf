/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 14:57:40 by ckurt             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/12/22 13:40:20 by ckurt            ###   ########lyon.fr   */
=======
/*   Updated: 2020/12/22 15:00:29 by ckurt            ###   ########lyon.fr   */
>>>>>>> test
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
		if (elem->dot_size == 0 && !elem->width)
			elem->dot_size = 1;
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
		str = ft_strdup("(null)");
		len = ft_strlen(str);
	}
	if (elem->left_justify)
		i += print_justify(elem, str, len);
	else
		i += print_else(elem, str, len);
	return (i);
}
