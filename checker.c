/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 21:49:34 by aouchaad          #+#    #+#             */
/*   Updated: 2023/03/19 16:30:07 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_and_exit(char **rule, t_list **stack_a, t_list **stack_b)
{
	free(*rule);
	free_stacks(stack_a, stack_b);
	print_error();
}

void	initial_func(int *i, t_list **stack_a, t_list **stack_b)
{
	*i = 0;
	*stack_a = NULL;
	*stack_b = NULL;
}

void	is_sorted(t_list **stack_a, t_list **stack_b)
{
	if (check_if_sorted(stack_a) == 1 && !(*stack_b))
		write(1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
	free_stacks (stack_a, stack_b);
}

void	free_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
}

int	main(int ac, char *av[])
{
	char	**args;
	char	*rule;
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;

	if (ac <= 1)
		return (0);
	args = arguments_check(av);
	initial_func(&i, &stack_a, &stack_b);
	while (args[i])
		stack_a = ft_lstnew(stack_a, ft_atoi(args[i++]));
	free_args(args);
	while (1)
	{
		rule = get_next_line(0);
		if (rule == NULL)
			break ;
		ruls (&rule, &stack_a, &stack_b);
	}
	is_sorted(&stack_a, &stack_b);
	return (0);
}
