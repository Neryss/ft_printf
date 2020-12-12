/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:08:58 by ckurt             #+#    #+#             */
/*   Updated: 2020/11/24 10:26:57 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_bzero(void *s, size_t n)
{
	unsigned char	*str;
	unsigned long	i;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
		str[i++] = '\0';
}
