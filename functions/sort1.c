/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpascua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:17:22 by alpascua          #+#    #+#             */
/*   Updated: 2025/01/27 15:50:31 by alpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

static int	ft_small(t_ps_list *a, int *small)
{
	int	pos;
	int	i;

	*small = a->rank;
	pos = 1;
	i = 1;
	while (a != NULL)
	{
		if (a->rank < *small)
		{
			*small = a->rank;
			pos = i;
		}
		a = a->next;
		i++;
	}
	return (pos);
}

static int	ft_pushsmall(t_ps_list **a, t_ps_list **b, char **ins, int len)
{
	int	small;
	int	pos;
	int	action;

	pos = ft_small(*a, &small);
	while ((*a)->rank != small)
	{
		if (pos == 2)
			action = swap(a, NULL, ins, "sa\n");
		else if (pos - 1 <= len / 2)
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

int	sort1(t_ps_list **a, t_ps_list **b, char **ins)
{
	int	len;

	len = ps_lstsize(*a) + 1;
	if (len == 2)
		return (0);
	while (--len > 2)
	{
		if (ft_pushsmall(a, b, ins, len) == -1)
			return (-1);
	}
	if ((*a)->rank > (*a)->next->rank)
	{
		if (swap(a, NULL, ins, "sa\n") == -1)
			return (-1);
	}
	while (*b != NULL)
	{
		if (push(a, b, ins, "pa\n") == -1)
			return (-1);
	}
	return (0);
}
