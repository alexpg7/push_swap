/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpascua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:02:35 by alpascua          #+#    #+#             */
/*   Updated: 2025/01/29 13:02:48 by alpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "list.h"

t_ps_list	*ps_lstnew(void *content)
{
	t_ps_list	*arr;

	arr = (t_ps_list *)malloc(sizeof(t_ps_list) * 1);
	if (!arr)
		return (NULL);
	arr->content = content;
	arr->next = NULL;
	arr->rank = 42;
	return (arr);
}

void	ps_lstadd_front(t_ps_list **lst, t_ps_list *new)
{
	if (!lst || !new)
		return ;
	new->next = lst[0];
	lst[0] = new;
}

int	ps_lstsize(t_ps_list *lst)
{
	int	cont;

	cont = 0;
	if (!lst)
		return (0);
	while (lst->next != NULL)
	{
		cont++;
		lst = lst->next;
	}
	return (cont + 1);
}

t_ps_list	*ps_lstlast(t_ps_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ps_lstadd_back(t_ps_list **lst, t_ps_list *new)
{
	t_ps_list	*aux;

	aux = *lst;
	if (lst && *lst)
	{
		while (aux->next != NULL)
			aux = aux->next;
		aux->next = new;
		while (new->next != NULL)
			new = new->next;
		new->next = NULL;
	}
	else if (lst)
		*lst = new;
	new->next = NULL;
}
