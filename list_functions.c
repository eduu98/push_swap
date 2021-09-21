#include "push_swap.h"

stack	*ft_stacknew(int content, int index)
{
	stack	*nodo;

	nodo = malloc(sizeof(stack));
	if (nodo == NULL)
		return (NULL);
	else
	{
		nodo->value = content;
		nodo->index = index;
		nodo->next = NULL;
	}
	return (nodo);
}
stack	*ft_stacklast(stack *stck)
{
	if (stck)
	{
		while (stck->next)
		{
			stck = stck->next;
		}
	}
	return (stck);
}
stack	*ft_stackprev(stack *stck, stack *actual)
{
	if (stck && stck != actual)
	{
		while (stck->next != actual)
		{
			stck = stck->next;
		}
	}
	return (stck);
}
void	ft_stackadd_back(stack **stck, stack *new)
{
	stack	*last;

	if (*stck)
	{
		last = ft_stacklast(*stck);
		last->next = new;
	}
	else
		*stck = new;
}
void	ft_stackadd_front(stack **alst, stack *new)
{
	new->next = *alst;
	*alst = new;
}
