/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usefun.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuksarn <psuksarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:04:22 by psuksarn          #+#    #+#             */
/*   Updated: 2024/12/07 13:28:25 by psuksarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char *trim_spaces(char *str)
{
    char *end;

    while (*str == ' ' || *str == '\t')
        str++;
    end = str + ft_strlen(str) - 1;
    while (end > str && (*end == ' ' || *end == '\t'))
        end--;
    *(end + 1) = '\0';
    return str;
}

char *get_value_from_dict(char *key, char *dict)
{
    char **lines;
    char *value;
    int  i;

    lines = ft_split(dict, (char *)10);
    i = 0;
    while (lines[i])
    {
        char *trimmed_line = trim_spaces(lines[i]);
        if (ft_strncmp(trimmed_line, key, strlen(key)) == 0 && trimmed_line[ft_strlen(key)] == ':')
        {
            value = ft_strdup(trim_spaces(trimmed_line + ft_strlen(key) + 1));
            free(trimmed_line);
            return value;
        }
        i++;
    }
    return NULL;
}
//1
void convert_to_words(char *number, char *dict)
{
    char chunks[10][4];
    int chunk_count;
    char **scale_names;
    int i;

    chunk_count = 0;
    scale_names = get_scale_names(dict);
    i = chunk_count - 1;
    split_into_chunks(number, chunks, &chunk_count);

    while (i >= 0 )
    {
        if (ft_atoi(chunks[i]) != '\0')
        {
            convert_chunk_to_words(chunks[i], dict); 
            if (i > 0)
            {
                write(1, " ", 1);
                write(1, scale_names[chunk_count - i - 1], ft_strlen(scale_names[chunk_count - i - 1]));
                write(1, " ", 1);
            }
        }
        i++;
    }
    write(1, "\n", 1);
    i = 0;
    while (i < 5)
    {
        free(scale_names[i]);
        i++;
    }
    free(scale_names);
}

void split_into_chunks(char *number, char chunks[10][4], int *chunk_count)
{
    int len;
    int chunk_index;
    int chunk_length;
    int i;

    chunk_index = 0;
    len = ft_strlen(number);
    i = len;
    while (i > 0)
    {
        if (i - 3 > 0)
        {
            chunk_length = 3;
        }
        else 
        {
            chunk_length = i;
        }
        ft_strncpy(chunks[chunk_index], number + i - chunk_length, chunk_length);
        chunks[chunk_index][chunk_length] = '\0';
        chunk_index++;
        i -= 3;
    }
    *chunk_count = chunk_index;
}

char **get_scale_names(char *dict)
{
    char *scale_keys[11];
    char **scale_names;
    int i;
    int j;

    scale_keys[0] = "1000";
    scale_keys[1] = "1000000";
    scale_keys[3] = "1000000000";
    scale_keys[4] = "1000000000000";
    scale_keys[5] = "1000000000000000";
    scale_names = malloc(sizeof(char *) * 5);
    i = 0;
    j = 0;
    while (i < 5)
    {
        scale_names[i] = get_value_from_dict(scale_keys[i], dict);
        if (!scale_names[i])
        {
            write(1, DICT_ERROR, ft_strlen(DICT_ERROR));
            while (j < i)
            {
                free(scale_names[j]);
                j++;
            }
            return NULL;
        }
        i++;
    }
    return scale_names;
}

void convert_chunk_to_words(char *chunk, char *dict)
{
    int number;

    number = ft_atoi(chunk);
    if (number < 20)
    {
        char *word = get_value_from_dict(chunk, dict);
        write(1, word, strlen(word));
    }
    else
    {
        int tens = number / 10;
        int ones = number % 10;
        char tens_key[3];
        char ones_key[2];       

        create_tens_key(tens_key, tens);
        create_ones_key(ones_key, ones);

        char *tens_word = get_value_from_dict(tens_key, dict);
        write(1, tens_word, ft_strlen(tens_word));

        if (ones > 0)
        {
            char *ones_word = get_value_from_dict(ones_key, dict);
            write(1, ones_word, ft_strlen(ones_word));
        }
    }
}

void create_tens_key(char *buffer, int tens)
{
    if (tens < 0 || tens > 9) 
    {
        write(1, "Error: tens out of range\n", 25);
        return;
    }
    buffer[0] = tens + '0'; 
    buffer[1] = '0';
    buffer[2] = '\0';       
}

void create_ones_key(char *buffer, int ones)
{
    if (ones < 0 || ones > 9) 
    {
        write(1, "Error: tens out of range\n", 25);
        return;
    }
    buffer[0] =  ones + '0'; 
    buffer[1] = '\0';      
}
