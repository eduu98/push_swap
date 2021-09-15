#include "push_swap.h"

/*
** Calculates number of moves to top of stack
*/

int	moves_to_start(t_elem *stack, int flag, int max)
{
	t_elem	*tmp;
	int		element;
	int		moves;

	moves = 0;
	if (stack)
	{
		tmp = stack;
		element = (flag == 1) ? 0 : max;
		moves++;
		while (tmp->index != element)
		{
			moves++;
			tmp = tmp->next;
		}
	}
	return(moves);
}

/*
** Calculates moves to bottom of stack
*/

int	moves_to_end(t_elem *stack, int flag, int max)
{
	t_elem	*tmp;
	int		element;
	int		moves;

	moves = 0;
	if (stack)
	{
		tmp = ft_stacklast(stack);
		element = (flag == 1) ? 0 : max;
		while (tmp->index != element)
		{
			moves++;
			tmp = ft_stackprev(stack, tmp);
		}
		moves++;
	}
	return(moves);
}

void	moves_smallest(t_elem *stack, int *s_rot, int *s_revrot, int max)
{
	if (stack)
	{
		*s_rot = moves_to_start(stack, 1, max);
		*s_revrot = moves_to_end(stack, 1, max);
		if (*s_rot <= *s_revrot)
			*s_revrot = -1;
		else
			*s_rot = -1;
	}
}

void	moves_biggest(t_elem *stack, int *b_rot, int *b_revrot, int max)
{
	if (stack)
	{
		*b_rot = moves_to_start(stack, 2, max);
		*b_revrot = moves_to_end(stack, 2, max);
		if (*b_rot <= *b_revrot)
			*b_revrot = -1;
		else
			*b_rot = -1;
	}
}

/*
** Calculates which has fewest moves to push to stack a:
** the biggest or smallest integer in stack b,
** either by rotating to the top or reverse rotating to the end.
*/

void		find_moves(t_elem *stack, char stack_name, int size)
{
	int small_rotate;
	int big_rotate;
	int small_revrotate;
	int big_revrotate;


	moves_smallest(stack, &small_rotate, &small_revrotate, size - 1);
	moves_biggest(stack, &big_rotate, &big_revrotate, size - 1);
	if (big_rotate != -1 && (big_rotate >= small_rotate &&
		big_rotate >= small_revrotate))
		big_rotate = -1;
	else if (big_revrotate != -1 && (big_revrotate >= small_rotate &&
		big_revrotate >= small_revrotate))
		big_revrotate = -1;
	else if (small_rotate != -1 && (small_rotate >= big_rotate &&
		small_rotate >= big_revrotate))
		small_rotate = -1;
	else if (small_revrotate != -1 && (small_revrotate >= big_rotate &&
		small_revrotate >= big_revrotate))
		small_revrotate = -1;
	/*
	if (small_rotate != -1 || small_revrotate != -1)
		SMALL_FLAG = 1;
	else if (big_rotate != -1 || big_revrotate != -1)
		BIG_FLAG = 1;
	*/
}
