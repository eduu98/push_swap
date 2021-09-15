#include "push_swap.h"

/**
 * Swap the first 2 elements at the top of the stack.
 * Do nothing if there is only one or no elements.
 */
void	do_swap(t_elem *stack)
{
	int		valueAux;
	t_elem	*secondElem;

	if(stack && stack->next)
	{
		printf ("DO SWAP\n");
		valueAux = stack->value;
		secondElem = stack->next;

		stack->value = secondElem->value;
		secondElem->value = valueAux;
	}
}

/**
 * take the first element at the top of stack 2 and put it at the top of stack 1.
 * Do nothing if stack 2 is empty.
 */
void	do_push(t_elem **stack1, t_elem **stack2)
{
	t_elem	*ElemAux;

	if(*stack2)
	{
		printf ("DO PUSH\n");
		ElemAux = (*stack2)->next;
		ft_stackadd_front(stack1, ft_stacknew((*stack2)->value));
		free(*stack2);
		*stack2 = NULL;
		*stack2 = ElemAux;
	}
}

/**
 * Shift up all elements of stack a by 1.
 * The first element becomes the last one.
 * Returns the stack modified
 */
t_elem	*do_rotate(t_elem *stack)
{
	t_elem	*ElemAux;
	t_elem	*ElemAux2;

	if(stack)
	{
		printf ("DO ROTATE\n");
		ElemAux = ft_stacklast(stack);
		ElemAux->next = stack;
		ElemAux2 = stack->next;
		stack->next = NULL;
		stack = ElemAux2;
	}
	return (stack);
}

/**
 * Shift down all elements of stack a by 1. The last element
 * becomes the first one
 * Returns the stack modified
 */
t_elem	*do_reverse_rotate(t_elem *stack)
{
	t_elem	*ElemAux;

	if(stack)
	{
		printf ("DO REVERSE ROTATE\n");
		ElemAux = ft_stacklast(stack);
		ElemAux->next = stack;
		while(stack->next != ElemAux)
			stack = stack->next;
		stack->next = NULL;
		stack = ElemAux;
	}
	return (stack);
}
