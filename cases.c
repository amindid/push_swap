/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:20:24 by aouchaad          #+#    #+#             */
/*   Updated: 2023/03/16 15:58:21 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	first_case(t_list **stack_a, t_list **stack_b, t_utils *utils)
{
	if (utils->a_pos >= utils->index)
	{
		while (utils->index-- > 0)
		{
			rr (stack_a, stack_b, 1);
			utils->a_pos--;
		}
		while (utils->a_pos-- > 0)
			ra (stack_a, 1);
	}
	else
	{
		while (utils->a_pos-- > 0)
		{
			rr (stack_a, stack_b, 1);
			utils->index--;
		}
		while (utils->index-- > 0)
			rb (stack_b, 1);
	}
	pa (stack_a, stack_b, 1);
}

void	second_case(t_list **stack_a, t_list **stack_b, t_utils *utils)
{
	if ((utils->num_a_arg - utils->a_pos) >= (utils->num_b_arg - utils->index))
	{
		while ((utils->num_b_arg - utils->index++) > 0)
		{
			rrr (stack_a, stack_b, 1);
			utils->a_pos++;
		}
		while ((utils->num_a_arg - utils->a_pos++) > 0)
			rra (stack_a, 1);
	}
	else
	{
		while ((utils->num_a_arg - utils->a_pos++) > 0)
		{
			rrr (stack_a, stack_b, 1);
			utils->index++;
		}
		while ((utils->num_b_arg - utils->index++) > 0)
			rrb (stack_b, 1);
	}
	pa (stack_a, stack_b, 1);
}

void	third_case(t_list **stack_a, t_list **stack_b, t_utils *utils)
{
	while (utils->a_pos > 0)
	{
		ra (stack_a, 1);
		utils->a_pos--;
	}
	while ((utils->num_b_arg - utils->index) > 0)
	{
		rrb (stack_b, 1);
		utils->index++;
	}
	pa (stack_a, stack_b, 1);
}

void	fourth_case(t_list **stack_a, t_list **stack_b, t_utils *utils)
{
	while (utils->index > 0)
	{
		rb (stack_b, 1);
		utils->index--;
	}
	while ((utils->num_a_arg - utils->a_pos) > 0)
	{
		rra (stack_a, 1);
		utils->a_pos++;
	}
	pa (stack_a, stack_b, 1);
}
