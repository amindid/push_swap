/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:02:20 by aouchaad          #+#    #+#             */
/*   Updated: 2023/03/16 17:27:38 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_strcmp(char **s1, char *s2)
{
    int i;

    i = 0;
    while (s2[i])
    {
        if (s2[i] != (*s1)[i])
            return (s2[i] - (*s1)[i]);
        if ((*s1)[i] == '\0')
            return (-1);
        i++;
    }
    return (0);
}