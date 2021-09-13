#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
# include "Libft/libft.h"

typedef struct s_elem
{
	int				value;
	int				index;
	struct s_elem	*next;
} t_elem;

t_elem	*ft_stacknew(int content);
t_elem	*ft_stacklast(t_elem *stack);
void	ft_stackadd_back(t_elem **stack, t_elem *new);
void	ft_stackadd_front(t_elem **alst, t_elem *new);
void	do_sa(t_elem *pila);
void	do_swap(t_elem *stack);
void	do_push(t_elem **stack1, t_elem **stack2);
t_elem	*do_rotate(t_elem *stack);
t_elem	*do_reverse_rotate(t_elem *stack);
int		ft_do_checks(int argc, char *argv[], t_elem **stack);

void	sortstack(t_elem *stack, int size);

#endif
