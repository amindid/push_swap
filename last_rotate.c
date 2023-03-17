/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:15:29 by aouchaad          #+#    #+#             */
/*   Updated: 2023/03/16 16:00:56 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	num_of_arg(t_list **stack_a, t_utils *utils)
{
	t_list	*temp;

	temp = *stack_a;
	utils->mini = temp->content;
	utils->min_index = 0;
	temp = temp->next;
	utils->arg_num = 1;
	while (temp)
	{
		utils->arg_num++;
		if (temp->content < utils->mini)
		{
			utils->mini = temp->content;
			utils->min_index = utils->arg_num - 1;
		}
		temp = temp->next;
	}
}

void	last_rotate(t_list **stack_a)
{
	t_utils	utils;

	num_of_arg (stack_a, &utils);
	if (utils.min_index <= (utils.arg_num / 2))
	{
		while (utils.min_index > 0)
		{
			ra (stack_a, 1);
			utils.min_index--;
		}
	}
	else
	{
		while ((utils.arg_num - utils.min_index) > 0)
		{
			rra (stack_a, 1);
			utils.min_index++;
		}
	}
}
