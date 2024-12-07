/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_dict.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:09:59 by lquehec           #+#    #+#             */
/*   Updated: 2023/08/20 15:11:00 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	file_size(char *dict)
{
	int		file;
	char	buffer[1024];
	int		count;
	int		bytes_read;

	file = open(dict, O_RDONLY);
	if (file == -1)
		return (-1);
	count = 0;
	while ((bytes_read = read(file, buffer, 1024)) > 0)
		count += bytes_read;
	close(file);
	return count;
}
int	check_file_size(char *dict)
{
	int	file_size;

	file_size = file_size(dict);
	if (file_size <= 0)
		return (0);
	return (1);
}
