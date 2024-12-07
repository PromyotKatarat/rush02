/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:02:47 by lquehec           #+#    #+#             */
/*   Updated: 2023/08/20 15:03:11 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>

# define DEFAULT_DICT "dicts/numbers.dict"

void	ft_error(void);
void	ft_error_dict(void);
int		ft_check_args(int argc, char **argv, char **dictpath, char **nbr);
int		ft_check_dict(char *dictpath);
int		file_size(char *dictpath);
int		ft_covert_nbr(char *dictpath, char *nbr);
int		ft_chunk_nbr_count(char *nb);
char	**ft_split_chunk_nbr(char *nbr, int size);
void	ft_free(char **dict, char **tab_nbr, char *nbr, char *zerovalue);
int		ft_print_puissance(int tab_nbr_size, char **dict);
int		ft_print_hundred(char *nbr, char **dict);
int		ft_print_tens(char *nbr, char **dict);
int		ft_print_chunk(char *nbr, char **dict);
int		ft_print_value(char *nbr, char **dict);
int		ft_number_len(char *str);
char	*ft_get_dict_value(char *str);
char	*ft_get_dict_number(char *line);
char	**ft_split(char *str, char *charset);
char	*ft_strndup(char *src, int size);
void	ft_putstr(char *str);
void	ft_putchar(char c);
int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(char *str);
int		ft_is_whitespace(char c);
int		ft_is_number(char c);

#endif
