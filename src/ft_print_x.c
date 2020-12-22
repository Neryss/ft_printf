/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 10:22:52 by ckurt             #+#    #+#             */
/*   Updated: 2020/12/22 10:36:22 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_print_x(t_element *elem, int nb, char *base)
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	str = ft_itoa_base(nb, base);
	len = ft_strlen(base);
	i += print_width(elem, len);
	i += ft_putstr(str);
	return (i);
}