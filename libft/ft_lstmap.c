/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 10:45:33 by ckurt             #+#    #+#             */
/*   Updated: 2020/12/03 09:15:22 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_lstmap_lstnew(void *content)
{
	t_list		*list;

	if (!(list = malloc(sizeof(t_list))))
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}

static void		ft_lstmap_lstclear(t_list **lst, void (*del)(void *))
{
	t_list		*temp;

	if (*lst)
	{
		while (*lst)
		{
			temp = (*lst)->next;
			del((*lst)->content);
			free(*lst);
			*lst = temp;
		}
	}
}

t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*res;
	t_list		*first;

	if (!lst || !(res = ft_lstmap_lstnew(lst->content)))
	{
		ft_lstmap_lstclear(&lst, del);
		return (NULL);
	}
	first = res;
	while (lst->next != NULL)
	{
		res->content = f(lst->content);
		lst = lst->next;
		if (!(res->next = ft_lstmap_lstnew(f(lst->content))))
		{
			ft_lstmap_lstclear(&first, del);
			return (NULL);
		}
		res = res->next;
	}
	return (first);
}
