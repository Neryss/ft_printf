/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 12:21:16 by ckurt             #+#    #+#             */
/*   Updated: 2020/12/21 17:16:21 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_p_width(s_element *elem, int len, char *str)
{
	int i;

	i = 0;
	i += print_width(elem, len + 2);
	i += ft_putstr("0x");
	i += ft_putstr(str);
	return (i);
}

int	ft_print_p(s_element *elem, size_t nb)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	str = ft_itoa_base(nb, "0123456789abcdef");
	len = ft_strlen(str);
	if (elem->left_justify)
	{
		i += ft_putstr("0x");
		i += ft_putstr(str);
		i += print_width(elem, len + 2);
	}
	else
		i += print_p_width(elem, len, str);	
	return (i);
}