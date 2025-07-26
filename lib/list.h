/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpascua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:13:20 by alpascua          #+#    #+#             */
/*   Updated: 2025/01/29 13:13:22 by alpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>

typedef struct ps_list
{
	void			*content;
	int				rank;
	int				cat;
	struct ps_list	*next;
}	t_ps_list;

t_ps_list	*ps_lstnew(void *content);

void		ps_lstadd_front(t_ps_list **lst, t_ps_list *new);

int			ps_lstsize(t_ps_list *lst);

t_ps_list	*ps_lstlast(t_ps_list *lst);

void		ps_lstadd_back(t_ps_list **lst, t_ps_list *new);

void		ps_lstdelone(t_ps_list *lst, void (*del)(void *));

void		ps_lstclear(t_ps_list **lst, void (*del)(void *));

void		ps_lstiter(t_ps_list *lst, void (*f)(void *));

t_ps_list	*ps_lstmap(t_ps_list *lst, void *(*f)(void *), void (*del)(void *));
