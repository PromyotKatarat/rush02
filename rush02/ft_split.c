/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuksarn <psuksarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:10:58 by psuksarn          #+#    #+#             */
/*   Updated: 2024/12/07 12:32:27 by psuksarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	is_separator(char c, char *sep)
{
	int	idx;

	idx = 0;
	while (sep[idx] != 0)
	{
		if (c == sep[idx])
			return (1);
		idx++;
	}
	return (0);
}

int	count_words(char *str, char *sep)
{
	int	idx;
	int	word_count;

	idx = 0;
	word_count = 0;
	while (str[idx] != 0)
	{
		if (!is_separator(str[idx], sep))
		{
			word_count++;
			while (str[idx] != 0 && !is_separator(str[idx], sep))
				idx++;
		}
		else
			idx++;
	}
	return (word_count);
}

char	*add_word(char *str, char *sep)
{
	int		idx;
	char	*word;

	idx = 0;
	while (str[idx] != 0 && !is_separator(str[idx], sep))
		idx++;
	word = malloc(sizeof(char) * (idx + 1));
	if (word == NULL)
		return (NULL);
	idx = 0;
	while (str[idx] != 0 && !is_separator(str[idx], sep))
	{
		word[idx] = str[idx];
		idx++;
	}
	word[idx] = 0;
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**str_array;
	int		str_idx;
	int		str_array_idx;
	int		array_size;

	array_size = count_words(str, charset);
	str_array = malloc (sizeof(char *) * (array_size + 1));
	str_idx = 0;
	str_array_idx = 0;
	if (str_array == NULL || str == NULL || charset == NULL)
		return (NULL);
	while (str[str_idx] != 0)
	{
		if (is_separator(str[str_idx], charset))
			str_idx++;
		else
		{
			str_array[str_array_idx] = add_word(&str[str_idx], charset);
			while (!is_separator(str[str_idx], charset) && str[str_idx] != 0)
				str_idx++;
			str_array_idx++;
		}
	}
	str_array[str_array_idx] = 0;
	return (str_array);
}
