#include "../checker.h"

static int	ft_doaction(t_ps_list **a, t_ps_list **b, char *ins)
{
	int	action;

	action = 0;
	if (ins[0] == 'r')
	{
		if (ins[1] == 'r' && ins[2] == 'a')
			action = c_rrotate(a);
		else if (ins[1] == 'r' && ins[2] == 'b')
			action = c_rrotate(b);
		else if (ins[1] == 'a')
			action = c_rotate(a);
		else if (ins[1] == 'b')
			action = c_rotate(b);
	}
	else if (ins[0] == 'p')
	{
		if (ins[1] == 'a')
			action = c_push(a, b);
		else if (ins[1] == 'b')
			action = c_push(b, a);
	}
	else if (ins[0] == 's')
	{
		if (ins[1] == 'a')
			action = c_swap(a);
		else if (ins[1] == 'b')
			action = c_swap(b);
	}
	return (action);
}

static int	checkorder(t_ps_list *a, t_ps_list *b)
{
	if (b)
		return (0);
	while (a->next)
	{
		if (ft_atoi(a->content) > ft_atoi(a->next->content))
			return (0);
		a = a->next;
	}
	return (1);
}

int	ft_operate(t_ps_list **a, t_ps_list **b, char *ins)
{
	int		i;
	int		len;
	char	*action;

	i = 0;
	while (ins[i])
	{
		len = ft_strchr(&ins[i], '\n') - &ins[i];
		action = ft_substr(ins, i, len + 1);
		if (ft_doaction(a, b, action) == -1)
		{
			free(action);
			return (-1);
		}
		free(action);
		while (ins[i] && ins[i] != '\n')
			i++;
		i++;
	}
	return (checkorder(*a, *b));
}
