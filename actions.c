/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecruz-go <ecruz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 14:03:21 by ecruz-go          #+#    #+#             */
/*   Updated: 2021/09/21 16:57:55 by ecruz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Swap the first 2 elements at the top of the stack.
 * Do nothing if there is only one or no elements.
 */
void	do_swap(t_stack *stk)
{
	int		valueAux;
	int		indexAux;
	t_stack	*secondElem;

	if(stk && stk->next)
	{
		printf ("DO SWAP\n");
		valueAux = stk->value;
		indexAux = stk->index;
		secondElem = stk->next;

		stk->value = secondElem->value;
		stk->index = secondElem->index;
		secondElem->value = valueAux;
		secondElem->index = indexAux;
	}
}

/**
 * take the first element at the top of stack 2 and put it at the top of stack 1.
 * Do nothing if stack 2 is empty.
 */
void	do_push(t_stack **stk1, t_stack **stk2)
{
	t_stack	*ElemAux;

	if(*stk2)
	{
		printf ("DO PUSH\n");
		ElemAux = (*stk2)->next;
		ft_stackadd_front(stk1, ft_stacknew((*stk2)->value, (*stk2)->index));
		free(*stk2);
		*stk2 = NULL;
		*stk2 = ElemAux;
	}
}

/**
 * Shift up all elements of stack a by 1.
 * The first element becomes the last one.
 * Returns the stack modified
 */
t_stack	*do_rotate(t_stack *stk)
{
	t_stack	*ElemAux;
	t_stack	*ElemAux2;

	if(stk)
	{
		printf ("DO ROTATE\n");
		ElemAux = ft_stacklast(stk);
		ElemAux->next = stk;
		ElemAux2 = stk->next;
		stk->next = NULL;
		stk = ElemAux2;
	}
	return (stk);
}

/**
 * Shift down all elements of stack a by 1. The last element
 * becomes the first one
 * Returns the stack modified
 */
t_stack	*do_reverse_rotate(t_stack *stk)
{
	t_stack	*ElemAux;

	if(stk)
	{
		printf ("DO REVERSE ROTATE\n");
		ElemAux = ft_stacklast(stk);
		ElemAux->next = stk;
		while(stk->next != ElemAux)
			stk = stk->next;
		stk->next = NULL;
		stk = ElemAux;
	}
	return (stk);
}
