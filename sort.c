/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecruz-go <ecruz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 12:14:32 by ecruz-go          #+#    #+#             */
/*   Updated: 2021/10/22 12:08:18 by ecruz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/**
 * Puts the numbers of the stack in an auxiliary array
 */
void	create_array(int **array, t_stack *aux, int size)
{
	int	i;
	int	*tmp;

	i = 0;
	tmp = *array;
	while (i < size)
	{
		tmp[i] = aux->value;
		aux = aux->next;
		i++;
	}
}

/**
 * Put the correct index of each number of the stack
 */
void	put_index(int *array, t_stack *aux)
{
	int	i;

	while (aux)
	{
		i = 0;
		while (array[i] != aux->value)
			i++;
		aux->index = i;
		aux = aux->next;
	}
}

/**
 * Creates an auxiliary array an order it
 * to have the proper index of each element
 * of the stack
 */
void	sortstack(t_stack **stk, int size)
{
	int		*array;
	long	tmp;
	int		i;

	tmp = 0;
	array = malloc((size + 1) * sizeof(int));
	create_array(&array, *stk, size);
	i = 0;
	while (i < size - 1)
	{
		if (array[i] <= array[i + 1])
			i++;
		else
		{
			tmp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = tmp;
			i = 0;
		}
	}
	put_index(array, *stk);
	free(array);
}
