/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 15:53:08 by ckurt             #+#    #+#             */
/*   Updated: 2020/11/27 08:47:54 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	int		i;

	i = 0;
	if (!(res = malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (0);
	ft_bzero(res, ft_strlen(s) + 1);
	while (s[i])
	{
		res[i] = f(i, s[i]);
		i++;
	}
	return (res);
}
