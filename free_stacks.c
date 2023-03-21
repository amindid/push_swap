/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:04:34 by aouchaad          #+#    #+#             */
/*   Updated: 2023/03/17 18:36:51 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stacks(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	while (*stack_a)
	{
		temp = (*stack_a)->next;
		free(*stack_a);
		*stack_a = temp;
	}
	while (*stack_b)
	{
		temp = (*stack_b)->next;
		free(*stack_b);
		*stack_b = temp;
	}
}
