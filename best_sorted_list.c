/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_sorted_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:00:42 by aouchaad          #+#    #+#             */
/*   Updated: 2023/03/16 15:57:12 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_stack_b(t_list **stack_a, t_list **stack_b, t_util1 *util1)
{
	int	i;
	int	j;
	int	count;

	j = 0;
	while (util1->number_of_args > 0)
	{
		i = j;
		count = 0;
		while (i < util1->numbers_index_len)
		{
			if (util1->numbers_index[i] == (*stack_a)->index)
			{
				j++;
				ra (stack_a, 1);
				count = 1;
				break ;
			}
			i++;
		}
		if (count == 0)
			pb (stack_a, stack_b, 1);
		util1->number_of_args--;
	}
	free (util1->numbers_index);
}

void	longst_sortd_list(t_util1 *util1)
{
	util1->i = 1;
	while (util1->i < util1->number_of_args)
	{
		util1->j = 0;
		while (util1->j < util1->i)
		{
			if (util1->numbers[util1->j] < util1->numbers[util1->i])
			{
				if ((util1->list_len[util1->j] + 1) >= (
						util1->list_len[util1->i]))
				{
					util1->list_len[util1->i] = util1->list_len[util1->j] + 1;
					util1->list_index[util1->i] = util1->j;
				}
			}
			util1->j++;
		}
		util1->i++;
	}
	util1->i = 1;
	util1->max_index = 0;
}

void	allocation_func(t_util1 *util1, t_list **stack_a)
{
	t_list	*temp;

	util1->i = 0;
	temp = (*stack_a);
	util1->number_of_args = 0;
	while (temp)
	{
		temp = temp->next;
		util1->number_of_args++;
	}
	util1->numbers = malloc (sizeof(int *) * util1->number_of_args);
	util1->list_len = malloc (sizeof(int *) * util1->number_of_args);
	util1->list_index = malloc (sizeof(int *) * util1->number_of_args);
	temp = (*stack_a);
	while (temp)
	{
		util1->numbers[util1->i] = temp->content;
		temp->index = util1->i;
		temp = temp->next;
		util1->i++;
	}
	util1->i = 0;
}

void	free_func(t_util1 *util1)
{
	free (util1->numbers);
	free (util1->list_len);
	free (util1->list_index);
}

void	best_sorted_list(t_list **stack_a, t_list **stack_b)
{
	t_util1	util1;

	allocation_func(&util1, stack_a);
	while (util1.i < util1.number_of_args)
		util1.list_len[util1.i++] = 1;
	longst_sortd_list (&util1);
	while (util1.i < util1.number_of_args)
	{
		if (util1.list_len[util1.i] >= util1.list_len[util1.max_index])
			util1.max_index = util1.i;
		util1.i++;
	}
	util1.numbers_index_len = util1.list_len[util1.max_index];
	util1.numbers_index = malloc (sizeof(int *) * (
				util1.list_len[util1.max_index]));
	util1.i = util1.list_len[util1.max_index] - 1;
	while (util1.i >= 0)
	{
		util1.numbers_index[util1.i] = util1.max_index;
		util1.max_index = util1.list_index[util1.max_index];
		util1.i--;
	}
	free_func (&util1);
	push_to_stack_b (stack_a, stack_b, &util1);
}
