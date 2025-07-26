/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpascua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:16:33 by alpascua          #+#    #+#             */
/*   Updated: 2025/01/27 17:36:32 by alpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

int	ft_errorfree(char **str)
{
	free(*str);
	str = NULL;
	return (-1);
}

int	swap(t_ps_list **a, t_ps_list **b, char **ins, char *str)
{
	t_ps_list	*auxlist;

	if (b)
		return (-1);
	if (ps_lstsize(*a) < 2 || !a || !(*a))
		return (0);
	auxlist = (*a)->next->next;
	(*a)->next->next = *a;
	(*a) = (*a)->next;
	(*a)->next->next = auxlist;
	if (ft_doins(ins, str) == -1)
		return (-1);
	return (0);
}

int	push(t_ps_list **a, t_ps_list **b, char **ins, char *str)
{
	t_ps_list	*aux;

	if (!(*b) || !b || !a)
		return (-1);
	aux = *b;
	*b = (*b)->next;
	ps_lstadd_front(a, aux);
	if (ft_doins(ins, str) == -1)
		return (-1);
	return (0);
}

int	rotate(t_ps_list **a, t_ps_list **b, char **ins, char *str)
{
	t_ps_list	*aux;

	if (b || !a)
		return (-1);
	if (ps_lstsize(*a) < 2)
		return (0);
	aux = *a;
	*a = (*a)->next;
	aux->next = NULL;
	ps_lstlast(*a)->next = aux;
	if (ft_doins(ins, str) == -1)
		return (-1);
	return (0);
}

int	rrotate(t_ps_list **a, t_ps_list **b, char **ins, char *str)
{
	t_ps_list	*aux;
	t_ps_list	*last;

	if (b || !a)
		return (-1);
	if (ps_lstsize(*a) < 2)
		return (0);
	aux = *a;
	last = ps_lstlast(*a);
	last->next = *a;
	while (aux->next != last)
		aux = aux->next;
	aux->next = NULL;
	*a = last;
	if (ft_doins(ins, str) == -1)
		return (-1);
	return (0);
}
