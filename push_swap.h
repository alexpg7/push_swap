/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpascua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:17:07 by alpascua          #+#    #+#             */
/*   Updated: 2025/01/27 16:01:07 by alpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lib/Libft/libft.h"
#include "lib/list.h"

int	swap(t_ps_list **a, t_ps_list **b, char **ins, char *str);

int	push(t_ps_list **a, t_ps_list **b, char **ins, char *str);

int	rotate(t_ps_list **a, t_ps_list **b, char **ins, char *str);

int	rrotate(t_ps_list **a, t_ps_list **b, char **ins, char *str);

int	ft_bubblesort(t_ps_list **a, t_ps_list **b, char **ins);

int	ft_distance(t_ps_list *a, int num, int mode);

void  ft_swap(int *a, int *b);

int	ft_doins(char **instructions, char *str);

int	ft_printlist(t_ps_list *a, t_ps_list *b, int mode);

int	sort1(t_ps_list **a, t_ps_list **b, char **ins);

int	sort2(t_ps_list **a, t_ps_list **b, char **ins);

int	sort3(t_ps_list **a, char **ins);

int	checkerror(char **argv, int narg);

int	ft_ranker(t_ps_list **a);

void	ft_cathegory(t_ps_list **a, int div);

int	sortcat(t_ps_list **a, t_ps_list **b, char **ins);

int	sortcat2(t_ps_list **a, t_ps_list **b, char **ins);

int	sortcathegory(t_ps_list **a, t_ps_list **b, char **ins, int div);

int	sortcathegory2(t_ps_list **a, t_ps_list **b, char **ins);
