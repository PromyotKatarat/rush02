/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuksarn <psuksarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 12:25:24 by psuksarn          #+#    #+#             */
/*   Updated: 2024/12/07 12:33:37 by psuksarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char *read_file(const char *filename)
{
    int fd;
    char buffer[BUFFER_SIZE + 1];
    char *content;
    int total_size = 0;
    int bytes_read;

    int max_size = 1024 * 1024; // 1MB
    content = malloc(max_size);
    if (!content)
        return NULL;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        free(content);
        return NULL;
    }
     while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        buffer[bytes_read] = '\0';

        if (total_size + bytes_read >= max_size)
        {
            write(1, DICT_ERROR, ft_strlen(DICT_ERROR));
            free(content);
            close(fd);
            return NULL;
        }
        ft_strcat(content, buffer);
        total_size += bytes_read;
    }
    close(fd);

    if (bytes_read < 0)
    {
        free(content);
        return NULL;
    }
    content[total_size] = '\0';
    return content;
}
int is_valid_number(const char *str)
{
    if (*str == '\0')
        return (0);
    while (*str)
    {
        if (*str < '0' || *str > '9')
            return (0);
        str++;
    }
    return (1);
}