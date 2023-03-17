/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_strlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:29:55 by aouchaad          #+#    #+#             */
/*   Updated: 2023/03/04 19:12:12 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	arg_strlen(char *string)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (string[i] == '-' || string[i] == '+')
		i++;
	while (string[i] && string[i] == '0')
		i++;
	while (string[i] != '\0')
	{
		i++;
		j++;
	}
	return (j);
}
