/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecruz-go <ecruz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 12:14:32 by ecruz-go          #+#    #+#             */
/*   Updated: 2021/10/15 19:38:25 by ecruz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	check_for_max(t_stack *stk, int *array)
{
	int	max;

	max = stk->value;
	while (stk)
	{
		*array = stk->value;
		if (max < stk->value)
			max = stk->value;
		stk = stk->next;
		array++;
	}
	*array = '\0';
	return (max);
}

// Using counting sort to sort the elements in the basis of significant places
void	counting_sort(int *array, int size, int place)
{
	int	*output;
	int	count[10];
	int	i;

	i = -1;
	while (++i < 10)
		count[i] = 0;
	i = -1;
	while (++i < size)
		count[(array[i] / place) % 10]++;
	i = 0;
	while (++i < 10)
		count[i] += count[i - 1];
	i = size;
	output = malloc(size * sizeof(int));
	while (--i >= 0)
	{
		output[count[(array[i] / place) % 10] - 1] = array[i];
		count[(array[i] / place) % 10]--;
	}
	i = -1;
	while (++i < size)
		array[i] = output[i];
	free(output);
}

// Main function to implement radix sort
void	sortstack(t_stack **stk, int size)
{
	int	*array;
	int	max;
	int	place;
	t_stack *aux;

	array = malloc(size + 1);
	aux = *stk;
	max = check_for_max(aux, array);
	place = 1;
	while (max / place > 0)
	{
		counting_sort(array, size, place);
		place *= 10;
	}
	while (aux)
	{
		place = 0;
		while (array[place] != aux->value)
			place++;
		aux->index = place;
		aux = aux->next;
	}
	free(array);
}
