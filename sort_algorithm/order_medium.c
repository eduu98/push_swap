/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_medium.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecruz-go <ecruz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 12:23:05 by ecruz-go          #+#    #+#             */
/*   Updated: 2021/10/22 12:13:28 by ecruz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * Move to the other stack the half of the numbers
 */
void	push_median(t_stack **stacka, t_stack **stackb, int split, int half)
{
	t_stack	*stackaux;
	t_stack	*stack_a_end;
	int		flag;

	stackaux = *stacka;
	stack_a_end = ft_stacklast(*stacka);
	flag = 1;
	while (flag)
	{
		if (stackaux == stack_a_end)
			flag = 0;
		if (split == 1 && stackaux->index <= half)
			do_push(stackb, stacka, 'b');
		else if (split == 2 && stackaux->index > half)
			do_push(stackb, stacka, 'b');
		else if (stackaux->index == 0)
			flag = 0;
		else
			*stacka = do_rotate(*stacka, 'a');
		stackaux = *stacka;
	}
}

/**
 * Order a stack of between 6 and 100 
 */
void	order_medium(t_stack **stacka, t_stack **stackb, int size)
{
	int		turns;
	int		rotates;
	t_moves	moves;

	rotates = 0;
	turns = 1;
	while (*stacka)
	{
		push_median(stacka, stackb, turns, (size / 2) - 1);
		moves = (t_moves){0, 0, 0, 0, 0, 0, 0, 0};
		while (*stackb)
		{
			find_min_max(*stackb, &moves);
			find_moves(*stackb, &moves);
			if (stackb && (moves.small_rotate >= 0 || moves.small_revrotate >= 0
					|| moves.big_rotate >= 0 || moves.big_revrotate >= 0))
				rotates += push_big_small(stacka, stackb, &moves);
		}
		while (--rotates)
			*stacka = do_rotate(*stacka, 'a');
		turns++;
		if (turns == 3)
			break ;
	}
}
