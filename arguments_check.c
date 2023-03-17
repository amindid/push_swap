/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:55:04 by aouchaad          #+#    #+#             */
/*   Updated: 2023/03/07 20:06:51 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_for_empty_string(char **av)
{
	int	i;
	int	j;
	int	count;

	i = 1;
	while (av[i])
	{
		j = 0;
		count = 0;
		if (av[i][0] == '\0')
			return (1);
		while (av[i][j])
		{
			if (av[i][j] != 32)
			{
				count++;
				break ;
			}
			j++;
		}
		i++;
	}
	if (count == 0)
		return (1);
	return (0);
}

int	non_digits(char **av, int *i, int *j, int *count)
{
	while (av[*i][*j])
	{
		if (av[*i][*j] == 32)
		{
			(*j)++;
			*count = 0;
		}
		if (av[*i][*j] == '+' || av[*i][*j] == '-')
		{
			(*count)++;
			if (av[*i][(*j) + 1] < 48 || av[*i][(*j) + 1] > 57 || *count > 1)
				return (1);
			(*j)++;
		}
		if (av[*i][*j] == '\0')
			break ;
		if ((av[*i][*j] < 48 || av[*i][*j] > 57) && av[*i][*j] != 32)
			return (1);
		if ((av[*i][*j] >= 48 || av[*i][*j] <= 57) && (
					av[*i][(*j) + 1] == '+' || av[*i][(*j) + 1] == '-'))
			return (1);
		(*j)++;
	}
	return (0);
}

int	check_for_non_digits(char **av)
{
	int	i;
	int	j;
	int	count;

	i = 1;
	while (av[i])
	{
		j = 0;
		count = 0;
		if (non_digits(av, &i, &j, &count) == 1)
			return (1);
		i++;
	}
	return (0);
}

int	check_for_duplicates(char **av)
{
	int		i;
	int		j;
	long	*numbers;
	int		number_of_args;

	number_of_args = how_meny_args(av);
	if (int_min_max(av, &numbers, number_of_args) == 1)
		return (1);
	i = 0;
	while (i < number_of_args)
	{
		j = i + 1;
		while (j < number_of_args)
		{
			if (numbers[i] == numbers[j])
			{
				free (numbers);
				return (1);
			}
			j++;
		}
		i++;
	}
	free (numbers);
	return (0);
}

char	**arguments_check(char **av)
{
	int		i;
	char	*av_for_duplicates_check;
	char	**arguments_splited;

	i = 1;
	av_for_duplicates_check = NULL;
	if (check_for_empty_string(av) == 1 || check_for_non_digits(av) == 1)
		print_error();
	while (av[i])
		av_for_duplicates_check = ft_strjoin(av_for_duplicates_check, av[i++]);
	arguments_splited = ft_split(av_for_duplicates_check, 32);
	i = 0;
	free(av_for_duplicates_check);
	if (check_for_duplicates(arguments_splited) == 1)
	{
		while (arguments_splited[i])
			free(arguments_splited[i++]);
		free (arguments_splited);
		print_error();
	}
	i = 0;
	while (arguments_splited[i])
		long_arg_check(arguments_splited, &i);
	return (arguments_splited);
}
