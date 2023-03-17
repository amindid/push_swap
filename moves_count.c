/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:54:06 by aouchaad          #+#    #+#             */
/*   Updated: 2023/03/07 16:44:00 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	b_pos(t_list **stack_b, t_utils *utils, int index)
{
	t_list	*temp_b;

	temp_b = *stack_b;
	while (temp_b)
	{
		if (temp_b->index == index)
			break ;
		utils->b_pos++;
		temp_b = temp_b->next;
	}
}

void	a_b_pos(t_list **stack_a, t_list **stack_b, t_utils *utils, int index)
{
	t_list	*temp_a;

	temp_a = *stack_a;
	while (temp_a)
	{
		if (temp_a->index == utils->perfect_pos)
			break ;
		utils->a_pos++;
		temp_a = temp_a->next;
	}
	temp_a = *stack_a;
	while (temp_a)
	{
		utils->num_a_arg++;
		temp_a = temp_a->next;
	}
	if (index == utils->perfect_pos)
		utils->a_pos = min_pos(stack_a);
	b_pos(stack_b, utils, index);
}

void	init_func(t_utils *utils)
{
	utils->count = 0;
	utils->a_pos = 0;
	utils->b_pos = 0;
	utils->num_a_arg = 0;
}

void	func(t_utils *utils)
{
	if (utils->a_pos >= utils->b_pos)
		utils->count = (utils->a_pos + 1);
	else
		utils->count = (utils->b_pos + 1);
}

int	moves_count(t_list **stack_a, t_list **stack_b, int index, t_utils *utils)
{
	init_func (utils);
	a_b_pos (stack_a, stack_b, utils, index);
	if (utils->a_pos <= (utils->num_a_arg / 2) && (
			utils->b_pos <= (utils->num_b_arg / 2)))
		func (utils);
	else if (utils->a_pos >= (utils->num_a_arg / 2) && (
			utils->b_pos >= (utils->num_b_arg / 2)))
	{
		if ((utils->num_a_arg - utils->a_pos) >= (
				utils->num_b_arg - utils->b_pos))
			utils->count = (utils->num_a_arg - utils->a_pos) + 1;
		else
			utils->count = (utils->num_b_arg - utils->b_pos) + 1;
	}
	else if (utils->a_pos <= (utils->num_a_arg / 2) && (
			utils->b_pos >= (utils->num_b_arg / 2)))
		utils->count = utils->a_pos + (utils->num_b_arg - utils->b_pos) + 1;
	else
		utils->count = utils->b_pos + (utils->num_a_arg - utils->a_pos) + 1;
	return (utils->count);
}
