/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_misc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpascua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:13:25 by alpascua          #+#    #+#             */
/*   Updated: 2025/01/29 17:17:00 by alpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

int long long	ft_maxatoi(const char *nptr)
{
	int				i;
	int long long	n;

	i = 0;
	n = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		n = n * 10 + (nptr[i] - '0');
		i++;
	}
	return (n);
}

int	ft_distance(t_ps_list *a, int num, int mode)
{
	int	pos;
	int	len;
	int	con;

	len = ps_lstsize(a);
	pos = 0;
	con = 0;
	if (!a)
		con = 0;
	else if (mode == 2)
		con = (a->rank != num);
	else if (mode == 3)
		con = (a->cat != num);
	while (con)
	{
		a = a->next;
		if (!a)
			con = 0;
		else if (mode == 2)
			con = (a->rank != num);
		else if (mode == 3)
			con = (a->cat != num);
		pos++;
	}
	if (pos < len - pos)
		return (pos);
	return (len - pos);
}

static int	cathegory(int num, int size, int div)
{
	int	i;

	i = 0;
	if (div > size)
		div = size;
	while (++i <= size)
	{
		if (num <= ((i * size) / div))
			return (i);
	}
	return (i);
}

void	ft_cathegory(t_ps_list **a, int div)
{
	t_ps_list	*aux;
	int			size;

	size = ps_lstsize(*a);
	aux = *a;
	while (aux != NULL)
	{
		aux->cat = cathegory(aux->rank, size, div);
		aux = aux->next;
	}
}

void  ft_swap(int *a, int *b)
{
  int temp;
  
  temp = *a;
  *a = *b;
  *b = temp;
}
