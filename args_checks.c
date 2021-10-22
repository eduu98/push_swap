/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecruz-go <ecruz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 12:04:42 by ecruz-go          #+#    #+#             */
/*   Updated: 2021/10/22 11:13:45 by ecruz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

/**
 * Prints error and exit program
 */
void	ft_print_error(void)
{
	write(1, "Error\n", 6);
	exit(0);
}

/**
 * Checks if the arguments given are valid
 */
int	ft_validargs(char *args)
{
	while (*args)
	{
		if (!ft_isdigit(*args) && *args != ' ' && *args != '-')
			return (0);
		args++;
	}
	return (1);
}

int	ft_atoi_ps(const char *str)
{
	int		i;
	long	resultado;
	long	signo;

	i = 0;
	resultado = 0;
	signo = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signo = -1;
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		resultado = resultado * 10 + (*(str + i) - '0');
		i++;
		if (resultado * signo > 2147483647 || resultado * signo < -2147483648)
			ft_print_error();
	}
	return (resultado * signo);
}

/**
 * Manage more than two args
 */
int	ft_various_args(int argc, char *argv[], t_stack **stack)
{
	int	count;

	count = 0;
	while (count < (argc - 1))
	{
		if (ft_validargs(argv[count]))
		{
			ft_stackadd_back(stack, ft_stacknew(ft_atoi_ps(argv[count]), 0));
		}
		else
			ft_print_error();
		count++;
	}
	return (1);
}

/**
 * Manage the arguments of the program and return them
 * in the array given on the third argument
 */
int	ft_do_checks(int argc, char *argv[], t_stack **stack)
{
	if (argc < 2)
		ft_print_error();
	else if (argc == 2)
	{
		if (ft_validargs(argv[1]))
		{
			while (*argv[1])
			{
				ft_stackadd_back(stack, ft_stacknew(ft_atoi_ps(argv[1]), 0));
				while (*argv[1] != ' ' && *argv[1])
					argv[1]++;
				if (*argv[1])
					argv[1]++;
			}
		}
		else
			ft_print_error();
	}
	else if (argc > 2)
	{
		argv++;
		return (ft_various_args(argc, argv, stack));
	}
	return (1);
}
