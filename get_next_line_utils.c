/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 19:53:52 by aouchaad          #+#    #+#             */
/*   Updated: 2023/03/16 15:29:50 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	_ft_strlen(char *string)
{
	int	i;

	i = 0;
	if (!string)
		return (0);
	while (string[i] != '\0')
		i++;
	return (i);
}

char	*_ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*ptr;
	size_t	k;

	k = _ft_strlen(s1);
	i = 0;
	j = 0;
	ptr = malloc(sizeof(char) * (k + _ft_strlen(s2) + 1));
	if (!ptr)
		return (NULL);
	while (s1 && i < k)
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2 && i < k + _ft_strlen(s2))
		ptr[i++] = s2[j++];
	ptr[i] = '\0';
	free(s1);
	return (ptr);
}

char	*ft_strchr(char *string, int chrstr)
{
	int		i;
	int		j;
	char	*save;

	i = 0;
	j = 0;
	while (string[i] != (char)chrstr)
	{
		if (string[i] == '\0')
			return (0);
		i++;
	}
	if (!string[i] || (string[i] == chrstr && string[i + 1] == '\0'))
		return (NULL);
	save = malloc (sizeof(char) * ((_ft_strlen(string) - i) + 1));
	if (!save)
		return (NULL);
	i++;
	while (i < _ft_strlen(string))
		save[j++] = string[i++];
	save[j] = '\0';
	return (save);
}
