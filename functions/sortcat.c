/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpascua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:27:33 by alpascua          #+#    #+#             */
/*   Updated: 2025/01/29 18:46:01 by alpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

static void	ft_smalls(t_ps_list *a, int *small1, int *small2)
{
	int			num;
	int			pos1;
	int			pos2;
	t_ps_list	*aux;

	aux = a;
	pos1 = 0;
	pos2 = 0;
	while (a != NULL)
	{
		num = a->cat;
		if (num < *small1)
			*small1 = num;
		a = a->next;
		pos1++;
	}
	while (aux != NULL)
	{
		num = aux->cat;
		if (num < *small2 && pos1 != pos2)
			*small2 = num;
		aux = aux->next;
		pos2++;
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
	while ((list)->cat != small)
	{
		list = list->next;
		pos++;
	}
	while ((*a)->cat != small)
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

	small1 = (*a)->cat;
	small2 = 2147483647;
	ft_smalls(*a, &small1, &small2);
	if (ft_distance(*a, small1, 3) > ft_distance(*a, small2, 3))
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
	if ((*a)->cat > (*a)->next->cat && s == 1)
		return (swap(a, NULL, ins, str));
	else if ((*a)->cat < (*a)->next->cat && s == -1)
		return (swap(a, NULL, ins, str));
	return (0);
}

int	sortcat(t_ps_list **a, t_ps_list **b, char **ins)
{
	int	len;

	len = ps_lstsize(*a);
	if (len == 2)
		return (ft_ifswap(a, ins, "sa\n", 1));
	while (len > 2)
	{
		if (ft_pushsmalls(a, b, ins) == -1)
			return (-1);
		if (ft_ifswap(b, ins, "sb\n", -1) == -1)
			return (-1);
		len = len - 2;
	}
	if (len == 2)
		return (ft_ifswap(a, ins, "sa\n", 1));
	return (0);
}
