/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 20:41:06 by aouchaad          #+#    #+#             */
/*   Updated: 2023/03/16 15:54:04 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **stack_a, int print)
{
	stack_swap (stack_a);
	if (print == 1)
		write (1, "sa\n", 3);
}

void	sb(t_list **stack_b, int print)
{
	stack_swap (stack_b);
	if (print == 1)
		write (1, "sb\n", 3);
}

void	ss(t_list **stack_a, t_list **stack_b, int print)
{
	stack_swap (stack_a);
	stack_swap (stack_b);
	if (print == 1)
		write (1, "ss\n", 3);
}

void	stack_swap(t_list **stack)
{
	t_list	*temp;
	t_list	*temp2;

	if (!(*stack))
		return ;
	if ((*stack)->next == NULL)
		return ;
	temp = (*stack)->next->next;
	temp2 = (*stack)->next;
	(*stack)->next->next = *stack;
	(*stack)->next = temp;
	*stack = temp2;
}
