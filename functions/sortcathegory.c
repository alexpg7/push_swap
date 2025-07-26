/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortcathegory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpascua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:47:21 by alpascua          #+#    #+#             */
/*   Updated: 2025/02/03 17:26:45 by alpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

static int	countnums(t_ps_list *a, int start)
{
	int			count;

	count = 0;
	while (a != NULL)
	{
		if ((a->cat == start) || (a->cat == start + 1))
			count++;
		a = a->next;
	}
	return (count);
}

static int	ft_pushsmalls(t_ps_list **a, t_ps_list **b, char **ins, int start)
{
	int	total;

	total = countnums(*a, start) + 1;
	while (--total > 0)
	{
		while (((*a)->cat != start) && ((*a)->cat != start + 1))
		{
			if (rotate(a, NULL, ins, "ra\n") == -1)
				return (-1);
		}
		if (push(b, a, ins, "pb\n") == -1)
			return (-1);
		if ((*b)->cat == start)
		{
			if (rotate(b, NULL, ins, "rb\n") == -1)
				return (-1);
		}
	}
	return (0);
}

int	sortcathegory(t_ps_list **a, t_ps_list **b, char **ins, int div)
{
	int	i;

	if (div % 2 != 0)
		return (-1);
	i = 1;
	while (i <= div)
	{
		if (ft_pushsmalls(a, b, ins, i) == -1)
			return (-1);
		i = i + 2;
	}
	return (0);
}

