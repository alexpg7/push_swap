/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortcathegory2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpascua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:24:42 by alpascua          #+#    #+#             */
/*   Updated: 2025/02/03 18:03:58 by alpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

static int	ft_index(t_ps_list *a, int num)
{
	int	i;

	i = 0;
	while (a)
	{
		i++;
		if (a->rank == num)
			return (i);
		a = a->next;
	}
	return (-1);
}

static int	ft_searchbig(t_ps_list *b, int big1)
{
	int	big;

	big = 0;
	while (b)
	{
		if (b->rank > big && b->rank != big1)
			big = b->rank;
		b = b->next;
	}
	return (big);
}

static int	pushnum(t_ps_list **a, t_ps_list **b, char **ins, int num)
{
	int	pos;
	int	len;
	int	action;

	pos = ft_index(*b, num);
	len = ps_lstsize(*b);
	while ((*b)->rank != num)
	{
		if (pos < len / 2)
			action = rotate(b, NULL, ins, "rb\n");
		else
			action = rrotate(b, NULL, ins, "rrb\n");
		if (action == -1)
			return (-1);
	}
	if (push(a, b, ins, "pa\n") == -1)
		return (-1);
	return (0);
}

static int	pushbigs(t_ps_list **a, t_ps_list **b, char **ins)
{
	int	big1;
	int	big2;
	int	d1;
	int	d2;

	big1 = ft_searchbig(*b, -1);
	big2 = ft_searchbig(*b, big1);
	d1 = ft_distance(*b, big1, 2);
	d2 = ft_distance(*b, big2, 2);
	if (d1 > d2)
		ft_swap(&big1, &big2);
	pushnum(a, b, ins, big1);
	pushnum(a, b, ins, big2);
	if (d1 > d2)
	{
		if (swap(a, NULL, ins, "sa\n") == -1)
			return (-1);
	}
	return (0);
}

int	sortcathegory2(t_ps_list **a, t_ps_list **b, char **ins)
{
	int	len;

	len = ps_lstsize(*b);
	while (len > 1)
	{
		if (pushbigs(a, b, ins) == -1)
			return (-1);
		len = len - 2;
	}
	if (len == 1)
	{
		if (push(a, b, ins, "pa\n") == -1)
			return (-1);
	}
	return (0);
}
