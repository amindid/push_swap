/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 21:49:34 by aouchaad          #+#    #+#             */
/*   Updated: 2023/03/17 17:09:38 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_and_exit(char **rule, t_list **stack_a, t_list **stack_b)
{
	free(*rule);
	free_stacks(stack_a, stack_b);
	print_error();
}

void    ruls(char **rule, t_list **stack_a, t_list **stack_b)
{
	if (ft_strcmp(rule, "sa\n") == 0)
		sa(stack_a, 0);		
	else if (ft_strcmp(rule, "sb\n") == 0)
		sb(stack_b, 0);
	else if (ft_strcmp(rule, "ra\n") == 0)
		ra(stack_a, 0);
	else if (ft_strcmp(rule, "rb\n") == 0)
		rb(stack_b, 0);
	else if (ft_strcmp(rule, "rra\n") == 0)
		rra(stack_a, 0);
	else if (ft_strcmp(rule, "rrb\n") == 0)
		rrb(stack_b, 0);
	else if (ft_strcmp(rule, "ss\n") == 0)
		ss(stack_a, stack_b, 0);
	else if (ft_strcmp(rule, "pa\n") == 0)
		pa(stack_a, stack_b, 0);
	else if (ft_strcmp(rule, "pb\n") == 0)
		pb(stack_a, stack_b, 0);
	else if (ft_strcmp(rule, "rr\n") == 0)
		rr(stack_a, stack_b, 0);
	else if (ft_strcmp(rule, "rrr\n") == 0)
		rrr(stack_a, stack_b, 0);
	else
		free_and_exit(rule, stack_a, stack_b);
	free (*rule);
}

void    is_sorted(t_list **stack_a, t_list **stack_b)
{
	if (check_if_sorted(stack_a) == 1)
		write(1, "OK\n", 3);
	else if (check_if_sorted(stack_a) == 0)
		write (1, "KO\n", 3);
	free_stacks (stack_a, stack_b);
}

void    free_args(char **args)
{
	int i;

	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
}

int main(int ac, char *av[])
{
	char **args;
	char *rule;
	t_list *stack_a;
	t_list *stack_b;
	int i;

	if (ac <= 1)
		return (0);
	args = arguments_check(av);
	i = 0;
	while (args[i])
		stack_a = ft_lstnew(stack_a, ft_atoi(args[i++]));
	free_args(args);
	stack_b = NULL;
	while (1)
	{
		rule = get_next_line(0);
		if (rule == NULL)
		{
			free (rule);
			break ;
		}
		ruls (&rule, &stack_a, &stack_b);
	}
	is_sorted(&stack_a, &stack_b);
}
