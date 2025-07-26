#include "../checker.h"

int	ft_errorfree(char **str)
{
	free(*str);
	str = NULL;
	return (-1);
}

int	c_swap(t_ps_list **a)
{
	t_ps_list	*auxlist;

	if (ps_lstsize(*a) < 2 || !a || !(*a))
		return (0);
	auxlist = (*a)->next->next;
	(*a)->next->next = *a;
	(*a) = (*a)->next;
	(*a)->next->next = auxlist;
	return (0);
}

int	c_push(t_ps_list **a, t_ps_list **b)
{
	t_ps_list	*aux;

	if (!(*b) || !b || !a)
		return (-1);
	aux = *b;
	*b = (*b)->next;
	ps_lstadd_front(a, aux);
	return (0);
}

int	c_rotate(t_ps_list **a)
{
	t_ps_list	*aux;

	if (!a)
		return (-1);
	if (ps_lstsize(*a) < 2)
		return (0);
	aux = *a;
	*a = (*a)->next;
	aux->next = NULL;
	ps_lstlast(*a)->next = aux;
	return (0);
}

int	c_rrotate(t_ps_list **a)
{
	t_ps_list	*aux;
	t_ps_list	*last;

	if (!a)
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
	return (0);
}
