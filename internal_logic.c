#include "push_swap.h"

int	check_for_max_min(t_elem *stack, int max)
{
	int aux;

	if (stack)
	{
		while (stack->next)
		{
			if (!aux || (max && aux < stack->value) || (!max && aux > stack->value))
				aux = stack->value;
			stack = stack->next;
		}
		if (!aux || (max && aux < stack->value) || (!max && aux > stack->value))
			aux = stack->value;
	}
	return (aux);
}

void	order_three(t_elem *stack)
{
	// buscar el maximo y minimo
	int max;
	int min;

	max = check_for_max_min(stack, 1);
	min = check_for_max_min(stack, 0);


	// comprobar si el maximo esta abajo

}