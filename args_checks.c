/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecruz-go <ecruz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 12:04:42 by ecruz-go          #+#    #+#             */
/*   Updated: 2021/09/21 12:48:09 by ecruz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

/**
 * Prints error and return 0
 */
int	ft_print_error(void)
{
	write(1, "Error", 5);
	return (0);
}

/**
 * Checks if the arguments given are valid
 */
int	ft_validargs(char *args)
{
	while (*args)
	{
		if (!ft_isdigit(*args) && *args != ' ')
			return (0);
		args++;
	}
	return (1);
}

/**
 * Manage more than two args
 */
int	ft_various_args(int argc, char *argv[], stack **stack)
{
	int	count;

	count = 0;
	while (count < (argc - 1))
	{
		if (ft_validargs(argv[count]))
			ft_stackadd_back(stack, ft_stacknew(ft_atoi(argv[count]), 0));
		else
			return (ft_print_error());
		count++;
	}
	return (1);
}

/**
 * Manage the arguments of the program and return them
 * in the array given on the third argument
 */
int	ft_do_checks(int argc, char *argv[], stack **stack)
{
	if (argc < 2)
		return (ft_print_error());
	else if (argc == 2)
	{
		if (ft_validargs(argv[1]))
		{
			while (*argv[1])
			{
				ft_stackadd_back(stack, ft_stacknew(ft_atoi(argv[1]), 0));
				while (*argv[1] != ' ' && *argv[1])
					argv[1]++;
				if (*argv[1])
					argv[1]++;
			}
		}
		else
			return (ft_print_error());
	}
	else if (argc > 2)
	{
		argv++;
		return (ft_various_args(argc, argv, stack));
	}
	return (1);
}
