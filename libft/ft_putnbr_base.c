/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 17:28:38 by ckurt             #+#    #+#             */
/*   Updated: 2020/12/15 17:40:11 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_putnbr_base(int nb, char *base)
{
	long		n;
	int			i;
	int			base_len;
	char		*res;

	res = malloc(2096 * sizeof(char));
	n = nb;
	nb = (n < 0 ? -1 : 1);
	n *= nb;
	i = 0;
	base_len = ft_strlen(base);
	while (base[base_len])
		base_len++;
	if (ft_check_base(base) && base_len > 1)
		while (n || i == 0)
		{
			res[i++] = base[n % base_len];
			n = n / base_len;
			res[i] = '\0';
		}
	if (nb < 0)
		res[i++] = '-';
	res[i] = '\0';
	ft_rev_tab(res);
	return (res);
}
