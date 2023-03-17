/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:56:50 by aouchaad          #+#    #+#             */
/*   Updated: 2023/03/07 16:22:52 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_sorted(t_list **stack_a)
{
	t_list	*temp;
	t_list	*temp1;
	int		num;

	temp = *stack_a;
	while (temp)
	{
		num = temp->content;
		temp1 = temp->next;
		while (temp1)
		{
			if (temp1->content < num)
				return (0);
			temp1 = temp1->next;
		}
		temp = temp->next;
	}
	return (1);
}
