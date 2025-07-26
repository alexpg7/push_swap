#include "../push_swap.h"

static int	checkorder(t_ps_list *a)
{
	while (a->next)
	{
		if (a->rank > a->next->rank)
			return (0);
		a = a->next;
	}
	return (1);
}

static int	sorting4(t_ps_list **a, char **ins)
{
	if ((*a)->next->rank == 1)
	{
		if (rotate(a, NULL, ins, "ra\n") == -1)
			return (-1);
	}
	else
	{
		if (swap(a, NULL, ins, "sa\n") == -1)
			return (-1);
		if (rrotate(a, NULL, ins, "rra\n") == -1)
			return (-1);
	}
	return (0);
}

static int	sorting3(t_ps_list **a, char **ins)
{
	int	action;

	action = 0;
	if ((*a)->rank == 1 && (*a)->next->rank == 3)
	{
		if (rotate(a, NULL, ins, "ra\n") == -1)
			return (-1);
		if (swap(a, NULL, ins, "sa\n") == -1)
			return (-1);
		if (rrotate(a, NULL, ins, "rra\n") == -1)
			return (-1);
	}
	else if ((*a)->rank == 2 && (*a)->next->rank == 1)
		action = swap(a, NULL, ins, "sa\n");
	else if ((*a)->rank == 2 && (*a)->next->rank == 3)
		action = rrotate(a, NULL, ins, "rra\n");
	else
		action = sorting4(a, ins);
	if (action == -1)
		return (-1);
	return (0);
}

int	sort3(t_ps_list **a, char **ins)
{
	int	order;
	int	size;

	size = ps_lstsize(*a);
	if (size == 1)
		return (0);
	order = checkorder(*a);
	if (order == 1)
		return (0);
	if (size == 2 && order == 0)
	{
		if (swap(a, NULL, ins, "sa\n") == -1)
			return (-1);
	}
	else if (sorting3(a, ins) == -1)
		return (-1);
	return (0);
}
