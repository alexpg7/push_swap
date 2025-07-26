/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ranker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpascua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:38:46 by alpascua          #+#    #+#             */
/*   Updated: 2025/01/29 13:56:13 by alpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

static int	ft_smallest(t_ps_list *a)
{
	int	small;

	small = ft_atoi(a->content);
	while (a != NULL)
	{
		if (ft_atoi(a->content) < small)
			small = ft_atoi(a->content);
		a = a->next;
	}
	return (small);
}

static int	ft_bigger(t_ps_list *a, int small)
{
	int	bigger;
	int	num;

	bigger = 2147483647;
	while (a != NULL)
	{
		num = ft_atoi(a->content);
		if (num < bigger && num > small)
			bigger = num;
		a = a->next;
	}
	return (bigger);
}

int	ft_ranker(t_ps_list **a)
{
	t_ps_list	*aux1;
	t_ps_list	*aux2;
	int			size;
	int			i;
	int			small;

	aux1 = *a;
	size = ps_lstsize(aux1);
	i = 0;
	while (++i <= size)
	{
		aux2 = aux1;
		if (i == 1)
			small = ft_smallest(aux2);
		else
			small = ft_bigger(aux2, small);
		while (ft_atoi(aux2->content) != small)
			aux2 = aux2->next;
		aux2->rank = i;
	}
	return (0);
}
