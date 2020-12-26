/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 21:49:04 by ckurt             #+#    #+#             */
/*   Updated: 2020/12/26 22:35:31 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_itoa_getsize(int n)
{
	int			count;

	count = 0;
	if (n < 0)
		n *= -1;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_uitoa(unsigned int nb)
{
	char	*res;
	long	n;
	int		count;
	int		i;

	n = nb;
	i = 0;
	if (n < 0)
		n *= -1;
	count = ft_itoa_getsize(n);
	if (!(res = ft_calloc(count + 1, sizeof(char))))
		return (NULL);
	while (count > i)
	{
		res[--count] = (n % 10) + '0';
		n /= 10;
	}
	return (res);
}