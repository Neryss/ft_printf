/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 12:21:16 by ckurt             #+#    #+#             */
/*   Updated: 2020/12/21 16:04:20 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

// static	int	get_len(int nb)
// {
// 	int	count;

// 	count = 0;
// 	while (nb)
// 	{
// 		nb /= 16;
// 		count++;
// 	}
// 	return (count);
// }

// char	ft_itoa_hexa(int nb);
// {
// 	char	*res;
// 	int		len;

// 	len = get_len(nb);
// 	if (nb < 0)
// 		len++;
// 	if (!(res = ft_calloc(count + 1, sizeof(char))))
// 		return (NULL);
// 	if (nb < 0)
// 		res[0] = '-';
// 	while (len > 0)
// 	{
// 		res[]
// 	}
// }

int	ft_print_p(s_element *elem, size_t nb)
{
	int	i;
	(void)elem;

	i = 0;

	i += ft_putstr("0x");
	i += ft_putstr(ft_itoa_base(nb, "0123456789abcdef"));
	return (i);
}