/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpascua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:17:22 by alpascua          #+#    #+#             */
/*   Updated: 2025/01/29 17:41:08 by alpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

static void	ft_smalls(t_ps_list *a, int *small1, int *small2)
{
	int			num;
	t_ps_list	*aux;

	aux = a;
	while (a != NULL)
	{
		num = a->rank;
		if (num < *small1)
			*small1 = num;
		a = a->next;
	}
	while (aux != NULL)
	{
		num = aux->rank;
		if (num < *small2 && num != *small1)
			*small2 = num;
		aux = aux->next;
	}
}

static int	ft_pushnum(t_ps_list **a, t_ps_list **b, char **ins, int small)
{
	int			pos;
	int			action;
	int			len;
	t_ps_list	*list;

	pos = 0;
	len = ps_lstsize(*a);
	list = *a;
	while ((list)->rank != small)
	{
		list = list->next;
		pos++;
	}
	while ((*a)->rank != small)
	{
		if (pos < len - pos)
			action = rotate(a, NULL, ins, "ra\n");
		else
			action = rrotate(a, NULL, ins, "rra\n");
		if (action == -1)
			return (-1);
	}
	if (push(b, a, ins, "pb\n") == -1)
		return (-1);
	return (0);
}

static int	ft_pushsmalls(t_ps_list **a, t_ps_list **b, char **ins)
{
	int	small1;
	int	small2;
	int	temp;

	small1 = (*a)->rank;
	small2 = 2147483647;
	ft_smalls(*a, &small1, &small2);
	if (ft_distance(*a, small1, 2) > ft_distance(*a, small2, 2))
	{
		temp = small1;
		small1 = small2;
		small2 = temp;
	}
	ft_pushnum(a, b, ins, small1);
	ft_pushnum(a, b, ins, small2);
	return (0);
}

static int	ft_ifswap(t_ps_list **a, char **ins, char *str, int s)
{
	if ((*a)->rank > (*a)->next->rank && s == 1)
	{
		if (swap(a, NULL, ins, str) == -1)
			return (-1);
	}
	else if ((*a)->rank < (*a)->next->rank && s == -1)
	{
		if (swap(a, NULL, ins, str) == -1)
			return (-1);
	}
	return (0);
}

int	sort2(t_ps_list **a, t_ps_list **b, char **ins)
{
	int	len;

	len = ps_lstsize(*a);
	if (len == 2)
		return (0);
	while (len > 2)
	{
		if (ft_pushsmalls(a, b, ins) == -1)
			return (-1);
		if (ft_ifswap(b, ins, "sb\n", -1) == -1)
			return (-1);
		len = len - 2;
	}
	if (len == 2)
	{
		if (ft_ifswap(a, ins, "sa\n", 1) == -1)
			return (-1);
	}
	while (*b != NULL)
	{
		if (push(a, b, ins, "pa\n") == -1)
			return (-1);
	}
	return (0);
}
