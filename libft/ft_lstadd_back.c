/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 17:43:17 by ckurt             #+#    #+#             */
/*   Updated: 2020/11/30 17:43:19 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *flink;

	flink = *lst;
	if (!*lst)
		*lst = new;
	else
	{
		while (flink->next != NULL)
			flink = flink->next;
		flink->next = new;
		new->next = NULL;
	}
}
