/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:47:01 by aouchaad          #+#    #+#             */
/*   Updated: 2023/03/07 19:29:03 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin(char *s1, char *s2)
{
	t_strjoin	variabls;
	char		*ptr;

	variabls.s1_len = ft_strlen(s1);
	variabls.totlen = variabls.s1_len + ft_strlen(s2);
	variabls.i = 0;
	variabls.j = 0;
	ptr = malloc(sizeof(char) * (variabls.totlen + 2));
	if (!ptr)
		return (NULL);
	while (s1 && variabls.i < variabls.s1_len)
	{
		ptr[variabls.i] = s1[variabls.i];
		variabls.i++;
	}
	ptr[variabls.i] = ' ';
	variabls.i++;
	while (s2 && variabls.i < variabls.totlen + 1)
		ptr[variabls.i++] = s2[variabls.j++];
	ptr[variabls.i] = '\0';
	free(s1);
	return (ptr);
}
