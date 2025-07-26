#include "checker.h"

void	ft_fill(t_ps_list **list, char **argv, int narg)
{
	int		i;

	i = 1;
	while (i < narg)
	{
		ps_lstadd_back(list,ps_lstnew((char *)argv[i]));
		i++;
	}
}

static void	ft_free2(t_ps_list **a)
{
	t_ps_list	*aux;

	if (!(*a))
		return ;
	while (*a)
	{
		aux = (*a)->next;
		free(*a);
		*a = aux;
	}
}

int	checkformat(char *line)
{
	size_t	len;

	len = ft_strlen(line);
	if (len >= 5)
		return (-1);
	if (len == 4)
	{
		if (line[0] == 'r' && line[1] && 'r')
		{
			if (line[2] == 'a' || line[2] == 'b')
				return (0);
		}
	}
	else if (len == 3)
	{
		if (line[0] == 's' || line[0] == 'r' || line[0] == 'p')
		{
			if (line[1] == 'a' || line[1] == 'b')
				return (0);
		}
	}
	return (-1);
}

static int	ft_read(char **ins)
{
	char	*line;
	char	*aux;
	int		error;

	error = 0;
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		aux = *ins;
		*ins = ft_strjoin(aux, line);
		error += checkformat(line);
		free(line);
		free(aux);
		if (!(*ins))
			return (-1);
	}
	if (error <= -1)
		return (-1);
	return (0);
}

int	main(int narg, char **argv)
{
	t_ps_list	*a;
	t_ps_list	*b;
	int			op;
	char		*ins;

	if (narg == 1)
		return (0);
	a = NULL;
	b = NULL;
	ins = (char *)malloc(sizeof(char));
	ins[0] = '\0';
	if (checkerror(argv + 1, narg - 2) == -1)
		return (write(2, "Error\n", 6));
	if (ft_read(&ins) == -1)
	{
		free(ins);
		return (write(2, "Error\n", 6));
	}
	ft_fill(&a, argv, narg);
	op = ft_operate(&a, &b, ins);
	free(ins);
	ft_free2(&a);
	ft_free2(&b);
	if (op == -1)
		return (write(2, "Error\n", 6));
	else if (op == 0)
		return (ft_printf("KO\n"));
	return (ft_printf("OK\n"));
}
