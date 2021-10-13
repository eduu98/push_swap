/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecruz-go <ecruz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 12:14:32 by ecruz-go          #+#    #+#             */
/*   Updated: 2021/10/13 13:04:10 by ecruz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	check_for_max(t_stack *stk, int *array)
{
	int	max;
	int	*aux;

	max = 0;
	aux = array;
	if (stk)
	{
		max = stk->value;
		while (stk->next)
		{
			*array = stk->value;
			if (max < stk->value)
				max = stk->value;
			stk = stk->next;
			array++;
		}
		*array = stk->value;
		if (max < stk->value)
			max = stk->value;
		array++;
		*array = '\0';
	}
	return (max);
}

// Using counting sort to sort the elements in the basis of significant places
void	counting_sort(int *array, int size, int place)
{
	int	output[size];
	int	count[10] = {0};
	int	i;

	i = 0;
	while (i < size)
	{
		count[(array[i] / place) % 10]++;
		i++;
	}
	i = 1;
	while (i < 10)
	{
		count[i] += count[i - 1];
		i++;
	}
	i = size - 1;
	while (i >= 0)
	{
		output[count[(array[i] / place) % 10] - 1] = array[i];
		count[(array[i] / place) % 10]--;
		i--;
	}
	i = 0;
	while (i < size)
	{
		array[i] = output[i];
		i++;
	}
}

// Main function to implement radix sort
void	sortstack(t_stack *stk, int size)
{
	int	*array;
	int	max;
	int	place;

	array = malloc(size + 1);
	max = check_for_max(stk, array);
	place = 1;
	while (max / place > 0)
	{
		counting_sort(array, size, place);
		place *= 10;
	}
	while (stk->next)
	{
		place = 0;
		while (array[place] != stk->value)
			place++;
		stk->index = place;
		stk = stk->next;
	}
	place = 0;
	while (array[place] != stk->value)
		place++;
	stk->index = place;
	free(array);
}
