#include "push_swap.h"

/**
 * Order a stack of two numbers
 * Compare if the first element is bigger than the second
 * and, if so, make a  swap
 */
void	order_two(t_elem **stack)
{
	if ((*stack)->index > (*stack)->next->index)
		do_swap(*stack);
}

/**
 * Order a stack of three numbers
 * Put the biggest number at the end
 * and then check the first two numbers
 */
void	order_three(t_elem **stack, int size)
{
	int big_revrotate;

	big_revrotate = moves_to_end(*stack, 2, size - 1);
	if (big_revrotate >= 1)
		while (big_revrotate-- > 1)
			*stack = do_reverse_rotate(*stack);
	order_two(stack);
}

/**
 * Order a stack of four numbers
 * Put the biggest number at the end
 * and then check the first three numbers
 */
void	order_four(t_elem **stacka, t_elem **stackb, int size)
{
	while ((*stacka)->index != 0)
		*stacka = do_rotate(*stacka);
	do_push(stackb, stacka);
	order_three(stacka, size);
	do_push(stacka, stackb);
}

void	order_five(t_elem **stacka, t_elem **stackb, int size)
{
	t_elem *stack_a_end;
	t_elem	*tmp;
	int		end;

	end = 0;
	stack_a_end = ft_stacklast(*stacka);
	while (end != 1)
	{
		*stacka == stack_a_end ? end = 1 : 0;
		if ((*stacka)->index < 2)
			do_push(stackb, stacka);
		else
			*stacka = do_rotate(*stacka);
	}
	order_three(stacka, size);
	tmp = (*stackb)->next;
	(*stackb)->index < tmp->index ? do_swap(*stackb) : 0;
	do_push(stacka, stackb);
	do_push(stacka, stackb);
}


void	order_small(t_elem **stacka, t_elem **stackb, int size)
{
	if (size == 2)
		order_two(stacka);
	else if (size == 3)
		order_three(stacka, size);
	else if (size == 4)
		order_four(stacka, stackb, size);
	else if (size == 5)
		order_five(stacka, stackb, size);

}