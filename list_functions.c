/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecruz-go <ecruz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 12:58:16 by ecruz-go          #+#    #+#             */
/*   Updated: 2021/10/15 16:41:41 by ecruz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

/**
 * Create new node for a stack
 */
t_stack	*ft_stacknew(int content, int index)
{
	t_stack	*nodo;

	nodo = malloc(sizeof(t_stack));
	if (nodo == NULL)
		return (NULL);
	else
	{
		nodo->value = content;
		nodo->index = index;
		nodo->next = NULL;
	}
	return (nodo);
}

/**
 * Get the last element of the stack
 */
t_stack	*ft_stacklast(t_stack *stck)
{
	if (stck)
	{
		while (stck->next)
		{
			stck = stck->next;
		}
	}
	return (stck);
}

/**
 * Get the previous element of the stack element given
 */
t_stack	*ft_stackprev(t_stack *stck, t_stack *actual)
{
	if (stck && stck != actual)
	{
		while (stck->next != actual)
		{
			stck = stck->next;
		}
	}
	return (stck);
}

/**
 * Add a node at the end of the stack
 */
void	ft_stackadd_back(t_stack **stck, t_stack *new)
{
	t_stack	*last;

	if (*stck)
	{
		last = ft_stacklast(*stck);
		last->next = new;
	}
	else
		*stck = new;
}

/**
 * Suprime y libera la memoria del elemento pasado
 * como parámetro y de todos los elementos siguientes,
 * con free
 * Por último, el puntero inicial debe pasar a NULL.
*/
void	ft_stkclear(t_stack **stk)
{
	t_stack	*aux;
	t_stack	*tmp;

	tmp = *stk;
	while (tmp)
	{
		aux = tmp;
		tmp = tmp->next;
		free(aux);
	}
	*stk = NULL;
}
