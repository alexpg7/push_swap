/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpascua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:17:00 by alpascua          #+#    #+#             */
/*   Updated: 2025/02/03 18:10:34 by alpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

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

int	ft_printlist(t_ps_list *a, t_ps_list *b, int mode)
{
	int	i;
	int	sizea;
	int	sizeb;
	int	r1;
	int	r2;
	int	c1;
	int	c2;
	int	p1;
	int	p2;

	sizea = ps_lstsize(a);
	sizeb = ps_lstsize(b);
	i = (sizea >= sizeb) * sizea + (sizea < sizeb) * sizeb;
	ft_printf("------------\n");
	while (i-- > 0)
	{
		if (a)
		{
			r1 = a->rank;
			c1 = a->cat;
			p1 = ft_atoi(a->content);
		}
		else
		{
			r1 = 0;
			c1 = 0;
			p1 = 0;
		}
		if (b)
		{
			r2 = b->rank;
			c2 = b->cat;
			p2 = ft_atoi(b->content);
		}
		else
		{
			r2 = 0;
			c2 = 0;
			p2 = 0;
		}
		if (mode == 1)
			ft_printf("%i\t%i\n", p1, p2);
		else if (mode == 2)
			ft_printf("%i\t%i\n", r1, r2);
		else if (mode == 3)
			ft_printf("%i\t%i\n", c1, c2);
		if (a)
			a = a->next;
		if (b)
			b = b->next;
	}
	ft_printf("------------\n");
	return (1);
}

int	ft_doins(char **instructions, char *str)
{
	char	*aux;

	aux = *instructions;
	*instructions = ft_strjoin(aux, str);
	free(aux);
	if (!(*instructions))
		return (-1);
	return (0);
}

static int	ft_listnum(t_ps_list **a, t_ps_list **b, char **ins, int size)
{
	int div;
	int	res;

	if (size <= 3)
		res = sort3(a, ins);
	else if (size <= 20)
		res = sort1(a, b, ins);
	else
	{
		if (size < 400)
			div = 8;
		else
			div = 18;
		ft_cathegory(a, div);
		if (sortcathegory(a, b, ins, div) == -1)
			return (-1);
		res = sortcathegory2(a, b, ins);
	}
	return (res);
}

int	main(int narg, char **argv)
{
	t_ps_list	*a;
	t_ps_list	*b;
	t_ps_list	*aux;
	char	*instructions;

	if (narg == 1)
		return (0);
	a = NULL;
	b = NULL;
	instructions = ft_strjoin(NULL, "");
	if (!instructions)
		return (write(2, "Error\n", 6));
	if (checkerror(argv + 1, narg - 2) == -1)
		return (write(2, "Error\n", 6));
	ft_fill(&a, argv, narg);
	ft_ranker(&a);
	if (ft_listnum(&a, &b, &instructions, ps_lstsize(a)) == -1)
		return (write(2, "Error\n", 6));
	if (ft_printf("%s", instructions) == -1)
		return (write(2, "Error\n", 6));
	free(instructions);
	while (a)
	{
		aux = a->next;
		free(a);
		a = aux;
	}
	return (0);
}
