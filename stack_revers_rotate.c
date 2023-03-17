/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_revers_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:54:24 by aouchaad          #+#    #+#             */
/*   Updated: 2023/03/16 15:54:52 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **stack_a, int print)
{
	stack_revers_rotate (stack_a);
	if (print == 1)
		write (1, "rra\n", 4);
}

void	rrb(t_list **stack_b, int print)
{
	stack_revers_rotate (stack_b);
	if (print == 1)
		write (1, "rrb\n", 4);
}

void	rrr(t_list **stack_a, t_list **stack_b, int print)
{
	stack_revers_rotate (stack_a);
	stack_revers_rotate (stack_b);
	if (print == 1)
		write (1, "rrr\n", 4);
}

void	stack_revers_rotate(t_list **stack)
{
	t_list	*temp;
	t_list	*temp2;
	int		count;

	if (!(*stack))
		return ;
	if ((*stack)->next == NULL)
		return ;
	temp = *stack;
	count = 0;
	while (temp->next != NULL)
	{
		temp = temp->next;
		count++;
	}
	temp->next = *stack;
	temp2 = temp;
	while (count > 0)
	{
		temp2 = temp2->next;
		count--;
	}
	temp2->next = NULL;
	*stack = temp;
}
