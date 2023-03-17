/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:52:39 by aouchaad          #+#    #+#             */
/*   Updated: 2023/03/16 15:54:27 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **stack_a, int print)
{
	stack_rotate (stack_a);
	if (print == 1)
		write (1, "ra\n", 3);
}

void	rb(t_list **stack_b, int print)
{
	stack_rotate (stack_b);
	if (print == 1)
		write (1, "rb\n", 3);
}

void	rr(t_list **stack_a, t_list **stack_b, int print)
{
	stack_rotate (stack_a);
	stack_rotate (stack_b);
	if (print == 1)
		write (1, "rr\n", 3);
}

void	stack_rotate(t_list **stack)
{
	t_list	*temp;
	t_list	*temp2;

	if (!(*stack))
		return ;
	if ((*stack)->next == NULL)
		return ;
	temp = *stack;
	temp2 = *stack;
	(*stack) = (*stack)->next;
	while (temp2->next != NULL)
		temp2 = temp2->next;
	temp2->next = temp;
	temp->next = NULL;
}
