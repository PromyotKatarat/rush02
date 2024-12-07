/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:58:53 by lquehec           #+#    #+#             */
/*   Updated: 2023/08/20 16:04:17 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	**ft_read_file(char *dict)
{
	char	*buffer;
	char	**split;
	int		file;
	int		size;
	int		bytes_read;

	size = ft_get_file_size(dict);
	if (size < 0)
		return (0);
	file = open(dict, O_RDONLY);
	if (file == -1)
		return (0);
	buffer = malloc (sizeof(char) * (size + 1));
	if (!buffer)
	{
		close (file);
		return (0);
	}
	bytes_read = read(file, buffer, size);
	buffer[size] = '\0';
	split = ft_split(buffer, "\n");
	free(buffer);
	close(file);
	return (split);
}

char	*ft_init_zerovalue(void)
{
	int		i;
	char	*zerovalue;

	i = 0;
	zerovalue = malloc(sizeof(char) * 4);
	if (!zerovalue)
		return (0);
	*zerovalue = 0;
	while (i < 3)
	{
		zerovalue[i] = '0';
		i++;
	}
	zerovalue[i] = 0;
	return (zerovalue);
}

int	ft_check_next_value(char **tab_nbr, char *zerovalue, int index)
{
	int		i;

	i = index;
	while (tab_nbr[i])
	{
		if (ft_strcmp(tab_nbr[i], zerovalue) > 0)
			return (1);
		i++;
	}
	return (0);
}

int	ft_start(char **dict, char **tab_nbr, int tab_nbr_size, char *zerovalue)
{
	int	i;

	i = 0;
	while (tab_nbr[i])
	{
		if (i > 0 && ft_strcmp(tab_nbr[i], zerovalue) > 0)
			ft_putchar(' ');
		ft_print_chunk(tab_nbr[i], dict);
		if (tab_nbr_size - i > 1 && ft_strcmp(tab_nbr[i], zerovalue) > 0)
		{
			ft_print_puissance(tab_nbr_size - i, dict);
		}
		i++;
	}
	ft_putchar('\n');
	return (1);
}

int	ft_covert_nbr(char *dict, char *nbr)
{
	char	**tab_nbr;
	char	**dict;
	char	*zerovalue;
	int		tab_nbr_size;

	dict = ft_read_file(dict);
	tab_nbr_size = ft_chunk_nbr_count(nbr);
	tab_nbr = ft_split_chunk_nbr(nbr, tab_nbr_size);
	zerovalue = ft_init_zerovalue();
	if (ft_strlen(nbr) == 1 && nbr[0] == '0')
	{
		ft_print_exact_value(nbr, dict);
		ft_putchar('\n');
		ft_free(dict, tab_nbr, nbr, zerovalue);
		return (1);
	}
	if (ft_start(dict, tab_nbr, tab_nbr_size, zerovalue))
	{
		ft_free(dict, tab_nbr, nbr, zerovalue);
		return (1);
	}
	ft_free(dict, tab_nbr, nbr, zerovalue);
	return (0);
}
