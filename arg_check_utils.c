/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:47:10 by aouchaad          #+#    #+#             */
/*   Updated: 2023/03/07 21:27:43 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	how_meny_args(char **arguments_splited)
{
	int	i;

	i = 0;
	while (arguments_splited[i])
		i++;
	return (i);
}

void	print_error(void)
{
	write (2, "Error\n", 6);
	exit (1);
}

void	long_arg_check(char **arg, int *i)
{
	if (arg_strlen(arg[*i]) > 10)
	{
		free (arg);
		print_error();
	}
	(*i)++;
}

int	int_min_max(char **av, long **numbers, int number_of_args)
{
	int	i;

	i = 0;
	(*numbers) = malloc(sizeof(long *) * (number_of_args));
	while (av[i])
	{
		(*numbers)[i] = ft_atod(av[i]);
		if ((*numbers)[i] > INT_MAX || (*numbers)[i] < INT_MIN)
		{
			free (*numbers);
			return (1);
		}
		i++;
	}
	return (0);
}
