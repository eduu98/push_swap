#include "push_swap.h"
#include <stdio.h>

int	ft_stackiter(t_elem *stack)
{
	int count;

	count = 0;
	if (stack)
	{
		while (stack->next)
		{
			printf("Value: %d || Order %d\n", stack->value, stack->index);
			stack = stack->next;
			count++;
		}
		count++;
		printf("Value: %d || Order %d\n", stack->value, stack->index);
	}
	return (count);
}



int main (int argc, char *argv[])
{
	t_elem	*stacka;
	t_elem	*stackb;
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
			{
				order_small(&stacka, &stackb, size);
			}
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