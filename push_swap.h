/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecruz-go <ecruz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 13:09:28 by ecruz-go          #+#    #+#             */
/*   Updated: 2021/10/20 11:28:16 by ecruz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "Libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

typedef struct s_moves
{
	int	small_rotate;
	int	big_rotate;
	int	small_revrotate;
	int	big_revrotate;
	int	small_flag;
	int	big_flag;
	int	min;
	int	max;
}	t_moves;

/* Stack Basic Functions */
t_stack	*ft_stacknew(int content, int index);
t_stack	*ft_stacklast(t_stack *stk);
t_stack	*ft_stackprev(t_stack *stk, t_stack *actual);
void	ft_stackadd_back(t_stack **stk, t_stack *new);
void	ft_stkclear(t_stack **stk);
/* Stack Operations */
void	do_sa(t_stack *pila, char stack_name);
void	do_swap(t_stack *stk, char stack_name);
void	do_push(t_stack **stk1, t_stack **stk2, char stack_name);
t_stack	*do_rotate(t_stack *stk, char stack_name);
t_stack	*do_reverse_rotate(t_stack *stk, char stack_name);

/* Moves to make*/
void	find_moves(t_stack *stk, t_moves *moves);
int		moves_to_end(t_stack *stk, int element);
int		ft_do_checks(int argc, char *argv[], t_stack **stk);

void	sortstack(t_stack **stk, int size);
/* Call Algorithms function */
void	order_small(t_stack **stka, t_stack **stkb, int size);
void	order_medium(t_stack **stacka, t_stack **stackb, int size);
void	order_big(t_stack **stacka, t_stack **stackb, int size);

void	rotate_and_push_to_a(t_stack **stka, t_stack **stkb,
			t_moves *moves, int *rotates);
int		push_big_small(t_stack **stka, t_stack **stkb, t_moves *moves);
void	find_min_max(t_stack *stk, t_moves *moves);

#endif
