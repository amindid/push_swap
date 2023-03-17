/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:03:36 by aouchaad          #+#    #+#             */
/*   Updated: 2023/03/06 11:05:01 by aouchaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	words_count(char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static char	*sting_allocation(int i, char *s, char c)
{
	int		string_len;
	char	*string;
	int		j;

	j = i;
	string_len = 0;
	while (s[i] != c && s[i])
	{
		string_len++;
		i++;
	}
	i = 0;
	string = malloc (sizeof(char) * (string_len + 1));
	if (!string)
		return (NULL);
	while (s[j] && s[j] != c)
		string[i++] = s[j++];
	string[i] = '\0';
	return (string);
}

char	**ft_split(char *s, char c)
{
	t_split	utils;

	utils.i = 0;
	utils.j = 0;
	if (!s)
		return (NULL);
	utils.word_count = words_count(s, c);
	utils.strings = malloc(sizeof(char *) * (utils.word_count + 1));
	if (!(utils.strings))
		return (NULL);
	while (s[utils.i] && utils.j < utils.word_count)
	{
		while (s[utils.i] == c && s[utils.i])
			utils.i++;
		if (s[utils.i] != c && s[utils.i])
		{
			utils.strings[utils.j] = sting_allocation(utils.i, s, c);
			utils.j++;
		}
		while (s[utils.i] != c && s[utils.i])
			utils.i++;
	}
	utils.strings[utils.j] = 0;
	return (utils.strings);
}
