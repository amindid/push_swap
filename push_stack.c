/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:49:09 by aouchaad          #+#    #+#             */
/*   Updated: 2023/03/16 15:55:12 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **stack_a, t_list **stack_b, int print)
{
	push_stack (stack_b, stack_a);
	if (print == 1)
		write (1, "pa\n", 3);
}

void	pb(t_list **stack_a, t_list **stack_b, int print)
{
	push_stack (stack_a, stack_b);
	if (print == 1)
		write (1, "pb\n", 3);
}

void	push_stack(t_list **stack_1, t_list **stack_2)
{
	t_list	*temp;

	if (!(*stack_1))
		return ;
	temp = *stack_2;
	*stack_2 = *stack_1;
	*stack_1 = (*stack_1)->next;
	(*stack_2)->next = temp;
}
