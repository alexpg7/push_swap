#ifndef CHECKER_H
# define CHECKER_H
# include "../lib/Libft/libft.h"
# include "../lib/list.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif
#endif
int	checkerror(char **argv, int narg);

char  *get_next_line(int fd);

int	ft_operate(t_ps_list **a, t_ps_list **b, char *ins);

int	c_swap(t_ps_list **a);

int	c_push(t_ps_list **a, t_ps_list **b);

int	c_rotate(t_ps_list **a);

int	c_rrotate(t_ps_list **a);
