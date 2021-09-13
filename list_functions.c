#include "push_swap.h"

t_elem	*ft_stacknew(int content)
{
	t_elem	*nodo;

	nodo = malloc(sizeof(t_elem));
	if (nodo == NULL)
		return (NULL);
	else
	{
		nodo->value = content;
		nodo->index = 0;
		nodo->next = NULL;
	}
	return (nodo);
}
t_elem	*ft_stacklast(t_elem *stack)
{
	if (stack)
	{
		while (stack->next)
		{
			stack = stack->next;
		}
	}
	return (stack);
}
void	ft_stackadd_back(t_elem **stack, t_elem *new)
{
	t_elem	*last;

	if (*stack)
	{
		last = ft_stacklast(*stack);
		last->next = new;
	}
	else
		*stack = new;
}
void	ft_stackadd_front(t_elem **alst, t_elem *new)
{
	new->next = *alst;
	*alst = new;
}
