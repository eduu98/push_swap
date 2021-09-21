#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include "stdio.h"
# include "Libft/libft.h"

typedef struct Stacks
{
	int				value;
	int				index;
	struct Stacks	*next;
} stack;

typedef struct Moves
{
	int	small_rotate;
	int	big_rotate;
	int	small_revrotate;
	int	big_revrotate;
	int small_flag;
	int big_flag;
} move;


/* Stack Basic Functions */
stack	*ft_stacknew(int content, int index);
stack	*ft_stacklast(stack *stk);
stack	*ft_stackprev(stack *stk, stack *actual);
void	ft_stackadd_back(stack **stk, stack *new);
void	ft_stackadd_front(stack **alst, stack *new);
/* Stack Operations */
void	do_sa(stack *pila);
void	do_swap(stack *stk);
void	do_push(stack **stk1, stack **stk2);
stack	*do_rotate(stack *stk);
stack	*do_reverse_rotate(stack *stk);

/* Moves to make*/
move	*find_moves(stack *stk, int size);
int		moves_to_end(stack *stk, int flag, int max);
int		ft_do_checks(int argc, char *argv[], stack **stk);

void	sortstack(stack *stk, int size);
/* Call Algorithms function */
void	order_small(stack **stka, stack **stkb, int size);
void	order_medium(stack **stacka, stack **stackb, int size);

/*!!!!!! PRUEBAS !!!!!!!*/
int	ft_stackiter(stack *stk);



#endif
