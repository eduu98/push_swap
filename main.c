/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecruz-go <ecruz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 12:14:41 by ecruz-go          #+#    #+#             */
/*   Updated: 2021/10/13 13:06:00 by ecruz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"
/**
 * Checks if there are duplicates in the stack,
 * if they are returns -1, else returns the
 * number of elements in the stack
*/
int	check_duplicates(t_stack *stk)
{
	int		count;
	t_stack	*aux;

	count = 0;
	while (stk->next)
	{
		aux = stk->next;
		while (aux)
		{
			if (stk->value == aux->value)
			{
				write(1, "Error\n", 6);
				return (-1);
			}
			aux = aux->next;
		}
		stk = stk->next;
		count++;
	}
	return (count);
}

int	main(int argc, char *argv[])
{
	t_stack	*stacka;
	t_stack	*stackb;
	int		size;

	if (ft_do_checks(argc, argv, &stacka))
	{
		if (stacka && stacka->next)
		{
			size = check_duplicates(stacka);
			if (size > 0)
			{
				sortstack(stacka, size);
				if (size <= 5)
					order_small(&stacka, &stackb, size);
				else if (size <= 100)
					order_medium(&stacka, &stackb, size);
				else if (size > 100)
					order_big(&stacka, &stackb, size);
			}
		}
	}
	return (0);
}
