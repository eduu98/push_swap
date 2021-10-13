/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_big.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecruz-go <ecruz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:06:07 by ecruz-go          #+#    #+#             */
/*   Updated: 2021/10/13 13:03:18 by ecruz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * Takes a quarter of stack A and moves it to stack b
 */
void	push_a_quarter(t_stack **stacka, t_stack **stackb, int num)
{
	if (*stackb && (*stackb)->index > num)
		*stackb = do_rotate(*stackb, 'b');
	do_push(stackb, stacka, 'b');
}

/**
 * Move to the other stack the quarter of the numbers
 */
void	push_quarters(t_stack **stacka, t_stack **stackb, int turn, int size)
{
	t_stack	*stackaux;
	t_stack	*stack_a_end;
	int		flag;

	stackaux = *stacka;
	stack_a_end = ft_stacklast(*stacka);
	flag = 0;
	while (flag != 1)
	{
		if (stackaux == stack_a_end)
			flag = 1;
		if (turn == 1 && stackaux->index <= size / 4)
			push_a_quarter(stacka, stackb, (size / 4) / 2);
		else if (turn == 2 && stackaux->index > size / 4
			&& stackaux->index <= size / 2)
			push_a_quarter(stacka, stackb, ((size / 2) / 4) * 3);
		else if (turn == 3 && stackaux->index > size / 2
			&& stackaux->index <= (size / 4) * 3)
			push_a_quarter(stacka, stackb, ((size / 2) / 4) * 5);
		else if (turn == 4 && stackaux->index > (size / 4) * 3)
			push_a_quarter(stacka, stackb, ((size / 2) / 4) * 7);
		else if (turn == 4 && stackaux->index == 0)
			break ;
		else
			*stacka = do_rotate(*stacka, 'a');
		stackaux = *stacka;
	}
}

/**
 * Order a stack of more than 100 numbers
 */
void	order_big(t_stack **stacka, t_stack **stackb, int size)
{
	int		turns;
	int		rotates;
	int		max;
	int		min;
	t_moves	moves;

	rotates = 0;
	turns = 1;
	while (*stacka)
	{
		push_quarters(stacka, stackb, turns, size);
		while (*stackb)
		{
			find_min_max(*stackb, &min, &max);
			moves = find_moves(*stackb, min, max);
			if (stackb && (moves.small_rotate >= 0 || moves.small_revrotate >= 0
					|| moves.big_rotate >= 0 || moves.big_revrotate >= 0))
				rotates += push_big_small(stacka, stackb, min, max, &moves);
		}
		while (--rotates)
			*stacka = do_rotate(*stacka, 'a');
		turns++;
		if (turns == 5)
			break ;
	}
}
