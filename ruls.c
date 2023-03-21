/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ruls.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:24:13 by aouchaad          #+#    #+#             */
/*   Updated: 2023/03/17 19:02:31 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ruls(char **rule, t_list **stack_a, t_list **stack_b)
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
