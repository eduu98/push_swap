/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecruz-go <ecruz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:09:53 by ecruz-go          #+#    #+#             */
/*   Updated: 2021/10/06 13:25:44 by ecruz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

/**
 * 
 */
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

/**
 * Finds the min and max of the stack given
 */
void	find_min_max(t_stack *stk, int *min, int *max)
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