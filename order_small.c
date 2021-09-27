/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_small.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecruz-go <ecruz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 12:04:22 by ecruz-go          #+#    #+#             */
/*   Updated: 2021/09/27 12:06:33 by ecruz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Order a stack of two numbers
 * Compare if the first element is bigger than the second
 * and, if so, make a  swap
 */
void	order_two(t_stack **stack)
{
	if ((*stack)->index > (*stack)->next->index)
		do_swap(*stack, 'a');
}

/**
 * Order a stack of three numbers
 * Put the biggest number at the end
 * and then check the first two numbers
 */
void	order_three(t_stack **stack, int size)
{
	int	big_revrotate;

	big_revrotate = moves_to_end(*stack, size - 1);
	if (big_revrotate >= 1)
		while (big_revrotate-- > 1)
			*stack = do_reverse_rotate(*stack, 'a');
	order_two(stack);
}

/**
 * Order a stack of four numbers
 * Put the biggest number at the end
 * and then check the first three numbers
 */
void	order_four(t_stack **stacka, t_stack **stackb, int size)
{
	while ((*stacka)->index != 0)
		*stacka = do_rotate(*stacka, 'a');
	do_push(stackb, stacka, 'b');
	order_three(stacka, size);
	do_push(stacka, stackb, 'a');
}

/**
 * Order a stack of five numbers
 * Put the two first numbers in stack b
 * and then check the first three numbers
 */
void	order_five(t_stack **stacka, t_stack **stackb, int size)
{
	t_stack	*stack_a_end;
	t_stack	*tmp;
	int		end;

	end = 0;
	stack_a_end = ft_stacklast(*stacka);
	while (end != 1)
	{
		if (*stacka == stack_a_end)
			end = 1;
		if ((*stacka)->index < 2)
			do_push(stackb, stacka, 'b');
		else
			*stacka = do_rotate(*stacka, 'a');
	}
	order_three(stacka, size);
	tmp = (*stackb)->next;
	if ((*stackb)->index < tmp->index)
		do_swap(*stackb, 'b');
	do_push(stacka, stackb, 'a');
	do_push(stacka, stackb, 'a');
}

/**
 * Order a stack of five or less numbers
 */
void	order_small(t_stack **stacka, t_stack **stackb, int size)
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
