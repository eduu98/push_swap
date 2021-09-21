#include "push_swap.h"

t_stack	*ft_stacknew(int content, int index)
{
	t_stack	*nodo;

	nodo = malloc(sizeof(t_stack));
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
t_stack	*ft_stacklast(t_stack *stck)
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
t_stack	*ft_stackprev(t_stack *stck, t_stack *actual)
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
void	ft_stackadd_back(t_stack **stck, t_stack *new)
{
	t_stack	*last;

	if (*stck)
	{
		last = ft_stacklast(*stck);
		last->next = new;
	}
	else
		*stck = new;
}
void	ft_stackadd_front(t_stack **alst, t_stack *new)
{
	new->next = *alst;
	*alst = new;
}
