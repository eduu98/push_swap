#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include "stdio.h"
# include "Libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
} t_stack;

typedef struct s_moves
{
	int	small_rotate;
	int	big_rotate;
	int	small_revrotate;
	int	big_revrotate;
	int small_flag;
	int big_flag;
} t_moves;


/* Stack Basic Functions */
t_stack	*ft_stacknew(int content, int index);
t_stack	*ft_stacklast(t_stack *stk);
t_stack	*ft_stackprev(t_stack *stk, t_stack *actual);
void	ft_stackadd_back(t_stack **stk, t_stack *new);
void	ft_stackadd_front(t_stack **alst, t_stack *new);
/* Stack Operations */
void	do_sa(t_stack *pila);
void	do_swap(t_stack *stk);
void	do_push(t_stack **stk1, t_stack **stk2);
t_stack	*do_rotate(t_stack *stk);
t_stack	*do_reverse_rotate(t_stack *stk);

/* Moves to make*/
t_moves	find_moves(t_stack *stk, int size);
int		moves_to_end(t_stack *stk, int element);
int		ft_do_checks(int argc, char *argv[], t_stack **stk);

void	sortstack(t_stack *stk, int size);
/* Call Algorithms function */
void	order_small(t_stack **stka, t_stack **stkb, int size);
void	order_medium(t_stack **stacka, t_stack **stackb, int size);

/*!!!!!! PRUEBAS !!!!!!!*/
int	ft_stackiter(t_stack *stk);



#endif
