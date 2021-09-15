#include "push_swap.h"

void	order_two(t_elem **stack)
{
	if ((*stack)->index > (*stack)->next->index)
		do_swap(*stack);
}

void	order_three(t_elem **stack, int size)
{
	t_elem	*tmp;
	int big_revrotate;

	big_revrotate = moves_to_end(*stack, 2, size - 1);
	if (big_revrotate >= 1)
		while (big_revrotate-- > 1)
			*stack = do_reverse_rotate(*stack);
	tmp = (*stack)->next;
	if ((*stack)->index > tmp->index)
		do_swap(*stack);
}


void	order_small(t_elem **stack, int size)
{
	if (size == 2)
		order_two(stack);
	else if (size == 3)
		order_three(stack, size);

}