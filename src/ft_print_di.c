/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 18:48:52 by ckurt             #+#    #+#             */
/*   Updated: 2020/12/25 12:10:09 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	print_di_justify(t_element *elem, char *str, int len)
{
	
}

int			ft_print_di(t_element *elem, int nb)
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	(void)elem;
	str = ft_itoa(nb);
	len = ft_strlen(str);
	i += ft_putstr(str);
	return (i);
}