/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:43:01 by lquehec           #+#    #+#             */
/*   Updated: 2023/08/20 15:43:05 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*ft_strndup(char *src, int size)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc (sizeof(char) * (size + 1));
	if (!dest)
		return (NULL);
	while (src[i] && i < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_find_char(char c, char *find_char)
{
	int	i;

	i = 0;
	while (find_char[i])
	{
		if (find_char[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_count_word_len(char *str, char *find_char)
{
	int	i;

	i = 0;
	while (str[i] && !ft_find_char(str[i], find_char))
		i++;
	return (i);
}

int	ft_count_word(char *str, char *find_char)
{
	int	i;
	int	count;
	int	word_len;

	i = 0;
	count = 0;
	word_len = 0;
	while (str[i])
	{
		while (str[i] && ft_find_char(str[i], find_char))
			i++;
		word_len = ft_count_word_len(str + i, find_char);
		if (word_len)
			count++;
		i += word_len;
		word_len = 0;
	}
	return (count);
}

char	**ft_split(char *str, char *find_char)
{
	int		i;
	int		j;
	int		word_len;
	int		count_word;
	char	**tab;

	i = 0;
	j = 0;
	word_len = 0;
	count_word = ft_count_word(str, find_char);
	tab = malloc(sizeof(char *) * (count_word + 1));
	if (!tab)
		return (NULL);
	while (str[i])
	{
		while (str[i] && ft_find_char(str[i], find_char))
			i++;
		word_len = ft_count_word_len(str + i, find_char);
		if (word_len)
			tab[j++] = ft_strndup(str + i, word_len);
		i += word_len;
		word_len = 0;
	}
	tab[j] = 0;
	return (tab);
}
