/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpascua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:02:52 by alpascua          #+#    #+#             */
/*   Updated: 2025/01/29 13:03:03 by alpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "list.h"

void	ps_lstdelone(t_ps_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

void	ps_lstclear(t_ps_list **lst, void (*del)(void *))
{
	t_ps_list	*aux;

	if (!lst)
		return ;
	while (*lst)
	{
		aux = (*lst)->next;
		ps_lstdelone(*lst, del);
		*lst = aux;
	}
}

void	ps_lstiter(t_ps_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}

t_ps_list	*ps_lstmap(t_ps_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_ps_list	*new;
	t_ps_list	*firstdir;

	if (!lst || !f || !del)
		return (0);
	new = ps_lstnew(f(lst->content));
	if (!new)
		return (0);
	firstdir = new;
	lst = lst->next;
	while (lst)
	{
		new->next = ps_lstnew(f(lst->content));
		if (!new)
		{
			ps_lstclear(&firstdir, del);
			return (0);
		}
		new = new->next;
		lst = lst->next;
	}
	new->next = NULL;
	return (firstdir);
}
