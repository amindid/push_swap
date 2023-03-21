/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:28:48 by aouchaad          #+#    #+#             */
/*   Updated: 2023/03/17 19:03:31 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	wanted_index(t_utils *utils, int *num_moves)
{
	utils->i = 0;
	while (utils->i < utils->num_b_arg)
	{
		if (num_moves[utils->i] < utils->min)
		{
			utils->min = num_moves[utils->i];
			utils->wanted_index = utils->i;
		}
		utils->i++;
	}
}

int	best_move(t_list **stack_a, t_list **stack_b, t_utils *utils)
{
	int		*num_moves;
	t_list	*temp;

	temp = *stack_b;
	utils->num_b_arg = 0;
	utils->i = 0;
	while (temp)
	{
		utils->num_b_arg++;
		temp = temp->next;
	}
	num_moves = malloc (sizeof(int *) * utils->num_b_arg);
	temp = *stack_b;
	while (temp)
	{
		utils->perfect_pos = perfect_pos(stack_a, stack_b, temp->index);
		num_moves[utils->i] = moves_count(stack_a, stack_b, temp->index, utils);
		utils->i++;
		temp = temp->next;
	}
	utils->min = num_moves[0];
	utils->wanted_index = 0;
	wanted_index(utils, num_moves);
	free (num_moves);
	return (utils->wanted_index);
}
