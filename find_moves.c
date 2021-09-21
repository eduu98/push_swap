#include "push_swap.h"

/*
** Calculates number of moves to top of stack
*/

int	moves_to_start(t_stack *stk, int flag, int max)
{
	t_stack	*tmp;
	int		element;
	int		moves;

	moves = 0;
	if (stk)
	{
		tmp = stk;
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

int	moves_to_end(t_stack *stk, int flag, int max)
{
	t_stack	*tmp;
	int		element;
	int		moves;

	moves = 0;
	if (stk)
	{
		tmp = ft_stacklast(stk);
		element = (flag == 1) ? 0 : max;
		while (tmp->index != element)
		{
			moves++;
			tmp = ft_stackprev(stk, tmp);
		}
		moves++;
	}
	return(moves);
}

void	moves_smallest(t_stack *stk, int *s_rot, int *s_revrot, int max)
{
	if (stk)
	{
		*s_rot = moves_to_start(stk, 1, max);
		*s_revrot = moves_to_end(stk, 1, max);
		if (*s_rot <= *s_revrot)
			*s_revrot = -1;
		else
			*s_rot = -1;
	}
}

void	moves_biggest(t_stack *stk, int *b_rot, int *b_revrot, int max)
{
	if (stk)
	{
		*b_rot = moves_to_start(stk, 2, max);
		*b_revrot = moves_to_end(stk, 2, max);
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

t_moves	*find_moves(t_stack *stk, int size)
{
	t_moves	*moves;

	*moves = (t_moves){0, 0, 0, 0};
	moves_smallest(stk, &moves->small_rotate, &moves->small_revrotate, size - 1);
	moves_biggest(stk, &moves->big_rotate, &moves->big_revrotate, size - 1);
	printf("CUALO\n");
	if (moves->big_rotate != -1 && (moves->big_rotate >= moves->small_rotate &&
		moves->big_rotate >= moves->small_revrotate))
		moves->big_rotate = -1;
	else if (moves->big_revrotate != -1 && (moves->big_revrotate >= moves->small_rotate &&
		moves->big_revrotate >= moves->small_revrotate))
		moves->big_revrotate = -1;
	else if (moves->small_rotate != -1 && (moves->small_rotate >= moves->big_rotate &&
		moves->small_rotate >= moves->big_revrotate))
		moves->small_rotate = -1;
	else if (moves->small_revrotate != -1 && (moves->small_revrotate >= moves->big_rotate &&
		moves->small_revrotate >= moves->big_revrotate))
		moves->small_revrotate = -1;
	if (moves->small_rotate != -1 || moves->small_revrotate != -1)
		moves->small_flag = 1;
	else if (moves->big_rotate != -1 || moves->big_revrotate != -1)
		moves->big_flag = 1;
	return (moves);
}
