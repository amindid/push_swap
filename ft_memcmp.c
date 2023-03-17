/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 20:17:33 by aouchaad          #+#    #+#             */
/*   Updated: 2023/03/15 16:52:23 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_memcmp(char *string1, char *string2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (string1[i] != string2[i])
			return (string1[i] - string2[i]);
		i++;
	}
	return (0);
}
