/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:40:49 by aouchaad          #+#    #+#             */
/*   Updated: 2023/03/07 16:47:49 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_pos(t_list **stack_a)
{
	t_list	*temp;
	int		min_pos;
	int		min_content;
	id_t	i;

	temp = *stack_a;
	min_pos = 0;
	i = 0;
	min_content = temp->content;
	while (temp)
	{
		if (min_content > temp->content)
		{
			min_content = temp->content;
			min_pos = i;
		}
		i++;
		temp = temp->next;
	}
	return (min_pos);
}
