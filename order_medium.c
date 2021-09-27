/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_medium.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecruz-go <ecruz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 12:23:05 by ecruz-go          #+#    #+#             */
/*   Updated: 2021/09/27 14:25:39 by ecruz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

/*
** Pushes biggest or smallest from stack B to stack A, in sorted order
*/

void	rotate_and_push_to_a(t_stack **stka, t_stack **stkb,
	t_moves *moves, int *rotates)
{
	if (moves->small_rotate >= 0)
		while (moves->small_rotate--)
			*stkb = do_rotate(*stkb, 'b');
	else if (moves->small_revrotate >= 0)
		while (moves->small_revrotate--)
			*stkb = do_reverse_rotate(*stkb, 'b');
	else if (moves->big_rotate >= 0)
		while (moves->big_rotate--)
			*stkb = do_rotate(*stkb, 'b');
	else if (moves->big_revrotate >= 0)
		while (moves->big_revrotate--)
			*stkb = do_reverse_rotate(*stkb, 'b');
	do_push(stka, stkb, 'a');
	if (moves->small_flag)
		*stka = do_rotate(*stka, 'a');
	if (moves->big_flag || !*stkb)
		(*rotates)++;
}

int	push_big_small(t_stack **stka, t_stack **stkb,
	int min, int max, t_moves *moves)
{
	t_stack	*stkaux;
	t_stack	*stkb_end;
	int		rotates;
	int		flag;

	stkaux = *stkb;
	stkb_end = ft_stacklast(*stkb);
	rotates = 0;
	flag = 1;
	while (flag)
	{		
		while (stkaux->index != min && stkaux->index != max)
			stkaux = stkaux->next;
		if (stkaux->index == min || stkaux->index == max)
		{
			rotate_and_push_to_a(stka, stkb, moves, &rotates);
			flag = 0;
		}
		else
			stkaux = stkaux->next;
		if (stkaux == stkb_end)
			flag = 0;
		stkaux = *stkb;
	}
	return (rotates);
}

void	find_biggest_smallest(t_stack *stk, int *min, int *max)
{
	t_stack		*tmp;
	t_stack		*end;

	tmp = stk;
	end = ft_stacklast(stk);
	*min = stk->index;
	*max = *min;
	while (1)
	{
		if (tmp->index <= *min)
			*min = tmp->index;
		if (tmp->index > *max)
			*max = tmp->index;
		if (tmp == end)
			break ;
		tmp = tmp->next;
	}
}

/**
 * Order a stack of between 6 and 100 
 */
void	order_medium(t_stack **stacka, t_stack **stackb, int size)
{
	int		split;
	int		rotates;
	int		max;
	int		min;
	t_moves	moves;

	rotates = 0;
	split = 1;
	while (*stacka)
	{
		push_median(stacka, stackb, split, (size / 2) - 1);
		while (*stackb)
		{
			find_biggest_smallest(*stackb, &min, &max);
			moves = find_moves(*stackb, min, max);
			if (stackb && (moves.small_rotate >= 0 || moves.small_revrotate >= 0
					|| moves.big_rotate >= 0 || moves.big_revrotate >= 0))
				rotates += push_big_small(stacka, stackb, min, max, &moves);
		}
		while (--rotates)
			*stacka = do_rotate(*stacka, 'a');
		split++;
		if (split == 3)
			break ;
	}
}
