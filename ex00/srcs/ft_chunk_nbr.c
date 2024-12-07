/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunk_nbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:37:55 by lquehec           #+#    #+#             */
/*   Updated: 2023/08/20 15:38:16 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	ft_chunk_nbr_count(char *nb)
{
	int	len;

	len = ft_strlen(nb) / 3;
	if (ft_strlen(nb) % 3 != 0)
		len++;
	return (len);
}

char	**ft_split_chunk_nbr(char *nbr, int size)
{
	char	**chunk_nbr;
	int		i;
	int		k;
	int		chunk_len;

	chunk_nbr = malloc(sizeof(char *) * (size + 1));
	if (!chunk_nbr)
		return (0);
	*chunk_nbr = 0;
	chunk_len = ft_strlen(nbr) % 3;
	i = 0;
	k = 0;
	if (chunk_len == 0)
		chunk_len = 3;
	while (nbr[i])
	{
		chunk_nbr[k++] = ft_strndup(nbr + i, chunk_len);
		i += chunk_len;
		if (chunk_len != 3)
			chunk_len = 3;
	}
	chunk_nbr[size] = 0;
	return (chunk_nbr);
}
