/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:43:02 by aouchaad          #+#    #+#             */
/*   Updated: 2023/03/15 19:05:02 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	more_than_five(t_list **stack_a, t_list **stack_b)
{
	best_sorted_list (stack_a, stack_b);
	push_to_a (stack_a, stack_b);
	last_rotate (stack_a);
	free_stacks(stack_a, stack_b);
}

int	main(int ac, char *av[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**arguments_splited;
	int		i;

	if (ac <= 1)
		return (0);
	arguments_splited = arguments_check(av);
	stack_a = NULL;
	stack_b = NULL;
	i = 0;
	while (arguments_splited[i])
		stack_a = ft_lstnew(stack_a, ft_atoi(arguments_splited[i++]));
	i = 0;
	while (arguments_splited[i])
		free(arguments_splited[i++]);
	free(arguments_splited);
	if (check_if_sorted(&stack_a) == 1)
		free_stacks(&stack_a, &stack_b);
	else if (ac <= 6)
		five_and_less_sort(&stack_a, &stack_b, ac);
	else
		more_than_five(&stack_a, &stack_b);
	return (0);
}
