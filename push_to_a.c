/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:17:53 by aouchaad          #+#    #+#             */
/*   Updated: 2023/03/07 12:54:45 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cases(t_list **stack_a, t_list **stack_b, t_utils *utils, int index)
{
	t_list	*temp_a;

	temp_a = *stack_a;
	while (temp_a)
	{
		if (temp_a->index == utils->pos)
			break ;
		utils->a_pos++;
		temp_a = temp_a->next;
	}
	if (utils->pos == index)
		utils->a_pos = min_pos(stack_a);
	if (utils->a_pos <= (utils->num_a_arg / 2) && (
			utils->index <= (utils->num_b_arg / 2)))
		first_case(stack_a, stack_b, utils);
	else if (utils->a_pos >= (utils->num_a_arg / 2) && (
			utils->index >= (utils->num_b_arg / 2)))
		second_case(stack_a, stack_b, utils);
	else if (utils->a_pos <= (utils->num_a_arg / 2) && (
			utils->index >= (utils->num_b_arg / 2)))
		third_case(stack_a, stack_b, utils);
	else if (utils->a_pos >= (utils->num_a_arg / 2) && (
			utils->index <= (utils->num_b_arg / 2)))
		fourth_case(stack_a, stack_b, utils);
}

void	push_to_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp_b;
	t_utils	utils;

	while (*stack_b)
	{
		temp_b = *stack_b;
		utils.index = best_move(stack_a, stack_b, &utils);
		utils.i = 0;
		while (temp_b)
		{
			if (utils.i == utils.index)
				break ;
			temp_b = temp_b->next;
			utils.i++;
		}
		utils.pos = perfect_pos(stack_a, stack_b, temp_b->index);
		utils.a_pos = 0;
		cases (stack_a, stack_b, &utils, temp_b->index);
	}
}
