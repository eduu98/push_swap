/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecruz-go <ecruz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 14:03:21 by ecruz-go          #+#    #+#             */
/*   Updated: 2021/09/27 14:21:12 by ecruz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

/**
 * Swap the first 2 elements at the top of the stack.
 * Do nothing if there is only one or no elements.
 */
void	do_swap(t_stack *stk, char stack_name)
{
	int		valueAux;
	int		indexAux;
	t_stack	*secondElem;

	if(stk && stk->next)
	{
		write(1, "s", 1);
		write(1, &stack_name, 1);
		write(1, "\n", 1);
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
void	do_push(t_stack **stk1, t_stack **stk2, char stack_name)
{
	t_stack	*ElemAux;

	if(*stk2)
	{
		write(1, "p", 1);
		write(1, &stack_name, 1);
		write(1, "\n", 1);
		ElemAux = (*stk2)->next;
		(*stk2)->next = *stk1;
		*stk1 = *stk2;
		*stk2 = ElemAux;
	}
}

/**
 * Shift up all elements of stack a by 1.
 * The first element becomes the last one.
 * Returns the stack modified
 */
t_stack	*do_rotate(t_stack *stk, char stack_name)
{
	t_stack	*ElemAux;
	t_stack	*ElemAux2;

	if(stk)
	{
		write(1, "r", 1);
		write(1, &stack_name, 1);
		write(1, "\n", 1);
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
t_stack	*do_reverse_rotate(t_stack *stk, char stack_name)
{
	t_stack	*ElemAux;

	if(stk)
	{
		write(1, "rr", 2);
		write(1, &stack_name, 1);
		write(1, "\n", 1);
		ElemAux = ft_stacklast(stk);
		ElemAux->next = stk;
		while(stk->next != ElemAux)
			stk = stk->next;
		stk->next = NULL;
		stk = ElemAux;
	}
	return (stk);
}
