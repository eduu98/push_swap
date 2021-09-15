#include "push_swap.h"
#include <stdio.h>

int check_for_max(t_elem *stack, int *array)
{
	int max;

	if (stack)
	{
		max = stack->value;
		while (stack->next)
		{
			*array = stack->value;
			if (max < stack->value)
				max = stack->value;
			stack = stack->next;
			array++;
		}
		if (max < stack->value)
			max = stack->value;
		*array = stack->value;
	}
	return (max);
}

// Using counting sort to sort the elements in the basis of significant places
void countingSort(int *array, int size, int place)
{
	int output[size + 1];
	int max = (array[0] / place) % 10;
	for (int i = 1; i < size; i++)
	{
		if (((array[i] / place) % 10) > max)
			max = array[i];
	}
	int count[max + 1];

	for (int i = 0; i < max; ++i)
		count[i] = 0;

	// Calculate count of elements
	for (int i = 0; i < size; i++)
		count[(array[i] / place) % 10]++;

	// Calculate cumulative count
	for (int i = 1; i < 10; i++)
		count[i] += count[i - 1];

	// Place the elements in sorted order
	for (int i = size - 1; i >= 0; i--)
	{
		output[count[(array[i] / place) % 10] - 1] = array[i];
		count[(array[i] / place) % 10]--;
	}

	for (int i = 0; i < size; i++)
		array[i] = output[i];
}

// Main function to implement radix sort
void sortstack(t_elem *stack, int size)
{
	int	*array;
	int max;
	int place;

	array = malloc(size + 1);
	max = check_for_max(stack, array);

	place = 1;
	while (max / place > 0)
	{
		countingSort(array, size, place);
		place *= 10;
	}

	place = 0;
	while (stack->next)
	{
		place = 0;
		while (array[place] != stack->value)
			place++;
		stack->index = place;		
		stack = stack->next;
	}
	place = 0;
	while (array[place] != stack->value)
		place++;
	stack->index = place;
	free(array);
}