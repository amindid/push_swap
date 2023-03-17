/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perfect_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:20:33 by aouchaad          #+#    #+#             */
/*   Updated: 2023/03/06 16:22:20 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	correct_pos(t_utils *utils, t_list **stack_a)
{
	t_list	*temp_a;

	temp_a = *stack_a;
	while (temp_a)
	{
		if (temp_a->content > utils->top_index_value)
		{
			utils->top_index = temp_a->index;
			utils->old_index_value = temp_a->content;
			temp_a = temp_a->next;
			while (temp_a)
			{
				if ((temp_a->content > utils->top_index_value) && (
						temp_a->content < utils->old_index_value))
				{
					utils->top_index = temp_a->index;
					utils->old_index_value = temp_a->content;
				}
				temp_a = temp_a->next;
			}
			break ;
		}
		temp_a = temp_a->next;
	}
}

int	perfect_pos(t_list **stack_a, t_list **stack_b, int node_index)
{
	t_list	*temp_b;
	t_utils	utils;

	temp_b = *stack_b;
	utils.top_index = node_index;
	while (temp_b)
	{
		if (temp_b->index == node_index)
		{
			utils.top_index_value = temp_b->content;
			correct_pos(&utils, stack_a);
			break ;
		}
		temp_b = temp_b->next;
	}
	return (utils.top_index);
}
