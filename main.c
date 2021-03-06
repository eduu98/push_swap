/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecruz-go <ecruz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 12:14:41 by ecruz-go          #+#    #+#             */
/*   Updated: 2021/10/22 12:09:56 by ecruz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
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
	count++;
	return (count);
}

/**
 * Checks if the stack is ordered by default
 */
int	sorted(t_stack *stka)
{
	t_stack	*aux;

	aux = stka->next;
	while (aux)
	{
		if (stka->value > aux->value)
			return (0);
		stka = stka->next;
		aux = aux->next;
	}
	return (1);
}

/**
 * Main function of push swap program
 */
int	main(int argc, char *argv[])
{
	t_stack	*stacka;
	t_stack	*stackb;
	int		size;

	stacka = NULL;
	stackb = NULL;
	if (ft_do_checks(argc, argv, &stacka))
	{
		if (stacka && stacka->next)
		{
			size = check_duplicates(stacka);
			if (size > 1 && !(sorted(stacka)))
			{
				sortstack(&stacka, size);
				if (size <= 5)
					order_small(&stacka, &stackb, size);
				else if (size <= 100)
					order_medium(&stacka, &stackb, size);
				else if (size > 100)
					order_big(&stacka, &stackb, size);
			}
		}
	}
	ft_stkclear(&stacka);
	return (0);
}
