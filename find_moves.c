#include "push_swap.h"

/*
** Calculates number of moves to top of stack
*/

int	moves_to_start(t_stack *stk, int element)
{
	t_stack	*tmp;
	int		moves;

	moves = 0;
	if (stk)
	{
		tmp = stk;
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

int	moves_to_end(t_stack *stk, int element)
{
	t_stack	*tmp;
	int		moves;

	moves = 0;
	if (stk)
	{
		tmp = ft_stacklast(stk);
		while (tmp->index != element)
		{
			moves++;
			tmp = ft_stackprev(stk, tmp);
		}
		moves++;
	}
	return(moves);
}

void	moves_smallest(t_stack *stk, t_moves *moves, int min)
{
	if (stk)
	{
		moves->small_rotate = moves_to_start(stk, min);
		moves->small_revrotate = moves_to_end(stk, min);
		if (moves->small_rotate <= moves->small_revrotate)
			moves->small_revrotate = -1;
		else
			moves->small_rotate = -1;
	}
}

void	moves_biggest(t_stack *stk, t_moves	*moves, int max)
{
	if (stk)
	{
		moves->big_rotate = moves_to_start(stk, max);
		moves->big_revrotate = moves_to_end(stk, max);
		if (moves->big_rotate <= moves->big_revrotate)
			moves->big_revrotate = -1;
		else
			moves->big_rotate = -1;
	}
}

/*
** Calculates which has fewest moves to push to stack a:
** the biggest or smallest integer in stack b,
** either by rotating to the top or reverse rotating to the end.
*/

t_moves	find_moves(t_stack *stk, int min, int max)
{
	t_moves	moves;

	moves = (t_moves){0, 0, 0, 0, 0, 0};
	moves_smallest(stk, &moves, min);
	moves_biggest(stk, &moves, max);
	if (moves.big_rotate != -1 && (moves.big_rotate >= moves.small_rotate &&
		moves.big_rotate >= moves.small_revrotate))
		moves.big_rotate = -1;
	else if (moves.big_revrotate != -1 && (moves.big_revrotate >= moves.small_rotate &&
		moves.big_revrotate >= moves.small_revrotate))
		moves.big_revrotate = -1;
	else if (moves.small_rotate != -1 && (moves.small_rotate >= moves.big_rotate &&
		moves.small_rotate >= moves.big_revrotate))
		moves.small_rotate = -1;
	else if (moves.small_revrotate != -1 && (moves.small_revrotate >= moves.big_rotate &&
		moves.small_revrotate >= moves.big_revrotate))
		moves.small_revrotate = -1;
	if (moves.small_rotate != -1 || moves.small_revrotate != -1)
		moves.small_flag = 1;
	else if (moves.big_rotate != -1 || moves.big_revrotate != -1)
		moves.big_flag = 1;
	return (moves);
}
