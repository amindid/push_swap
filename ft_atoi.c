/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:08:27 by aouchaad          #+#    #+#             */
/*   Updated: 2023/03/06 11:00:19 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *string)
{
	int	sign;
	int	res;
	int	i;

	sign = 1;
	res = 0;
	i = 0;
	while (string[i] == 32 || (string[i] >= 9 && string[i] <= 13))
		i++;
	if (string[i] == '-' || string[i] == '+')
	{
		if (string[i++] == '-')
			sign = -1;
	}
	if (string[i] < 48 && string[i] > 57)
		return (0);
	while (string[i] >= 48 && string[i] <= 57)
	{
		res *= 10;
		res += string[i++] - 48;
	}
	return (res * sign);
}
