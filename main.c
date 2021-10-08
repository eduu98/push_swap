/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecruz-go <ecruz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 12:14:41 by ecruz-go          #+#    #+#             */
/*   Updated: 2021/10/08 12:35:19 by ecruz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

/**
 * Returns the number of elements in the stack
*/
int	ft_stksize(t_stack *stk)
{
	int	count;

	count = 0;
	if (stk)
	{
		while (stk->next)
		{
			count++;
			stk = stk->next;
		}
		count++;
	}
	return (count);
}

int main (int argc, char *argv[])
{
	t_stack	*stacka;
	t_stack	*stackb;
	int size;

	if (ft_do_checks(argc, argv, &stacka))
	{
		if (stacka && stacka->next)
		{
			size = ft_stksize(stacka);
			sortstack(stacka, size);
			if (size <= 5)
				order_small(&stacka, &stackb, size);
			else if (size <= 100)
				order_medium(&stacka, &stackb, size);
			else if (size > 100)
				order_big(&stacka, &stackb, size);	
		}
	}
	return(0);
}