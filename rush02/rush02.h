/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuksarn <psuksarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:33:57 by psuksarn          #+#    #+#             */
/*   Updated: 2024/12/07 13:28:55 by psuksarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

# define ERROR "Error\n"
# define DICT_ERROR "Dict Error\n"
# define BUFFER_SIZE 1024

char    *read_file(const char *filename);
void    convert_chunk_to_words(char *chunk, char *dict);
char    **get_scale_names(char *dict);
void    split_into_chunks(char *number, char chunks[10][4], int *chunk_count);
void    convert_to_words(char *number, char *dict);
char    *get_value_from_dict(char *key, char *dict);
char    *trim_spaces(char *str);
int is_valid_number(const char *str);
void    print_error(const char *error_msg);
void create_ones_key(char *buffer, int ones);
void create_tens_key(char *buffer, int tens);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
char	**ft_split(char *str, char *charset);
int	ft_atoi(char *str);
int ft_strlen(char *str);
char    *ft_strdup(char *str);
char	*ft_strcat(char *dest, char *src);
int ft_strncmp(char *dest, char *str, int nbr);

#endif