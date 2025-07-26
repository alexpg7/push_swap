/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortcat2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpascua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:38:03 by alpascua          #+#    #+#             */
/*   Updated: 2025/01/29 18:06:24 by alpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

static void	ft_bigs(t_ps_list *a, int *big1, int *big2)
{
	int			num;
	t_ps_list	*aux;

	aux = a;
	while (a != NULL)
	{
		num = a->rank;
		if (num > *big1)
			*big1 = num;
		a = a->next;
	}
	while (aux != NULL)
	{
		num = aux->rank;
		if (num > *big2 && num != *big1)
			*big2 = num;
		aux = aux->next;
	}
}

static int	ft_pushnum(t_ps_list **a, t_ps_list **b, char **ins, int big)
{
	int			pos;
	int			action;
	int			len;
	t_ps_list	*list;

	pos = 0;
	len = ps_lstsize(*a);
	list = *a;
	while ((list)->rank != big)
	{
		list = list->next;
		pos++;
	}
	while ((*a)->rank != big)
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

static int	ft_pushbigs(t_ps_list **a, t_ps_list **b, char **ins)
{
	int	big1;
	int	big2;
	int	temp;

	big1 = (*a)->rank;
	big2 = -2147483648;
	ft_bigs(*a, &big1, &big2);
	if (ft_distance(*a, big1, 2) > ft_distance(*a, big2, 2))
	{
		temp = big1;
		big1 = big2;
		big2 = temp;
	}
	ft_pushnum(a, b, ins, big1);
	ft_pushnum(a, b, ins, big2);
	return (0);
}

static int	ft_ifswap(t_ps_list **a, char **ins, char *str, int s)
{
	if ((*a)->rank < (*a)->next->rank && s == 1)
	{
		if (swap(a, NULL, ins, str) == -1)
			return (-1);
	}
	else if ((*a)->rank > (*a)->next->rank && s == -1)
	{
		if (swap(a, NULL, ins, str) == -1)
			return (-1);
	}
	return (0);
}

int	sortcat2(t_ps_list **a, t_ps_list **b, char **ins)
{
	int	len;

	len = ps_lstsize(*a);
	if (len == 2)
		return (0);
	while (len > 0)
	{
		if (ft_pushbigs(a, b, ins) == -1)
			return (-1);
		if (ft_ifswap(b, ins, "sb\n", -1) == -1)
			return (-1);
		len = len - 2;
	}
	return (0);
}
