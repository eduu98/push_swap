/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecruz-go <ecruz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 12:14:41 by ecruz-go          #+#    #+#             */
/*   Updated: 2021/10/04 18:40:51 by ecruz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	ft_stackiter(t_stack *stk)
{
	int count;

	count = 0;
	if (stk)
	{
		while (stk->next)
		{
			printf("Value: %d || Order %d\n", stk->value, stk->index);
			stk = stk->next;
			count++;
		}
		count++;
		printf("Value: %d || Order %d\n", stk->value, stk->index);
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
		if (stacka)
		{
			printf("Todo Correcto\n");
			size = ft_stackiter(stacka);
			printf("-----------------------------\n");
			sortstack(stacka, size);
			ft_stackiter(stacka);
			printf("-----------------------------\n");
			if (size <= 5)
				order_small(&stacka, &stackb, size);
			else if (size <= 100)
				order_medium(&stacka, &stackb, size);
			else
				
			printf("-----------------------------\n");
			ft_stackiter(stacka);
			
		}
		else
		{
			printf("\nCadena vacia");
		}
	}
	return(0);
}