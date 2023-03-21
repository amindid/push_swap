/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_and_less_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:38:01 by aouchaad          #+#    #+#             */
/*   Updated: 2023/03/19 16:44:58 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	copie_to_array(t_list **stack_a, int **num)
{
	t_list	*temp;
	int		i;

	temp = *stack_a;
	i = 0;
	while (temp)
	{
		(*num)[i] = temp->content;
		i++;
		temp = temp->next;
	}
}

void	three_arg_sort(t_list **stack_a)
{
	int	*num;

	num = malloc (sizeof(int *) * 3);
	copie_to_array(stack_a, &num);
	if ((num[0] < num[1]) && (num[0] < num[2]) && (num[1] > num[2]))
	{
		rra (stack_a, 1);
		sa (stack_a, 1);
	}
	else if ((num[2] < num[0]) && (num[2] < num[1]) && (num[0] < num[1]))
		rra (stack_a, 1);
	else if ((num[1] < num[0]) && (num[1] < num[2]) && (num[0] < num[2]))
		sa (stack_a, 1);
	else if ((num[1] < num[0]) && (num[1] < num[2]) && (num[2] < num[0]))
		ra (stack_a, 1);
	else if ((num[2] < num[0]) && (num[2] < num[1]) && (num[1] < num[0]))
	{
		sa (stack_a, 1);
		rra (stack_a, 1);
	}
	free (num);
}

void	five_and_four(t_list **stack_a, t_list **stack_b, int ac)
{
	int	i;

	while (ac > 3)
	{
		i = min_pos(stack_a);
		if (i <= (ac / 2))
		{
			while (i-- > 0)
				ra (stack_a, 1);
		}
		else
		{
			while ((ac - i++) > 0)
				rra (stack_a, 1);
		}
		pb (stack_a, stack_b, 1);
		ac--;
	}
	three_arg_sort(stack_a);
	while (*stack_b)
		pa (stack_a, stack_b, 1);
}

void	five_and_less_sort(t_list **stack_a, t_list **stack_b, int ac)
{
	if (ac == 2)
		sa (stack_a, 1);
	else if (ac == 3)
		three_arg_sort(stack_a);
	else if (ac >= 4)
		five_and_four(stack_a, stack_b, ac);
	free_stacks(stack_a, stack_b);
	exit (0);
}
