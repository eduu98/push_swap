/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_medium.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecruz-go <ecruz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 12:23:05 by ecruz-go          #+#    #+#             */
/*   Updated: 2021/09/23 14:08:01 by ecruz-go         ###   ########.fr       */
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
			do_push(stackb, stacka);
		else if (split == 2 && stackaux->index > half)
			do_push(stackb, stacka);
		else if (stackaux->index == 0)
			flag = 0;
		else
			*stacka = do_rotate(*stacka);			
		stackaux = *stacka;
	}
}

/*
** Pushes biggest or smallest from stack B to stack A, in sorted order
*/

void	rotate_and_push_to_a(t_stack **stka, t_stack **stkb, t_moves *moves, int *rotates)
{
	if (moves->small_rotate >= 0)
		while (moves->small_rotate--)
			*stkb = do_rotate(*stkb);
	else if (moves->small_revrotate >= 0)
		while (moves->small_revrotate--)
			*stkb = do_reverse_rotate(*stkb);
	else if (moves->big_rotate >= 0)
		while (moves->big_rotate--)
			*stkb = do_rotate(*stkb);
	else if (moves->big_revrotate >= 0)
		while (moves->big_revrotate--)
			*stkb = do_reverse_rotate(*stkb);
	do_push(stka, stkb);
	if (moves->small_flag)
		*stka = do_rotate(*stka);
	if (moves->big_flag || !*stkb)
		*rotates++;
}

int	push_big_small(t_stack **stka, t_stack **stkb, int half, t_moves *moves)
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
		while (stkaux->index != 0 && stkaux->index != half)
			stkaux = stkaux->next;
		if (stkaux->index == 0 || stkaux->index == half)
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


/**
 * Order a stack of between 6 and 100 
 */
void	order_medium(t_stack **stacka, t_stack **stackb, int size)
{
	int		split;
	int		half;
	int		rotates;
	t_moves	moves;

	rotates = 0;
	split = 1;
	half = (size / 2) - 1;
	while (*stacka)
	{
		push_median(stacka, stackb, split, half);
		while (*stackb)
		{
			moves = find_moves(*stackb, half);
			if (stackb && (moves.small_rotate >= 0 || moves.small_revrotate >= 0
				|| moves.big_rotate >= 0 || moves.big_revrotate >= 0))
				rotates += push_big_small(stacka, stackb, half, &moves);
		}
		printf("HOLA %d\n", rotates);
		while (--rotates)
			*stacka = do_rotate(*stacka);
		
		printf("STACK A\n");
		ft_stackiter(*stacka);
		printf("STACK B\n");
		ft_stackiter(*stackb);
		
		split++;
		if (split == 3)
			break ;
	}
}