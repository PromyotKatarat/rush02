/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuksarn <psuksarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:33:53 by psuksarn          #+#    #+#             */
/*   Updated: 2024/12/07 13:54:54 by psuksarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int main(int argc, char** argv)
{
    char *dict_content;

    if (argc != 2 && argc != 3)
    {
        write(1, ERROR, strlen(ERROR));
        return 1;
    }
    if (argc == 3)
        dict_content = read_file(argv[1]);
    else
        dict_content = read_file("numbers.dict");

    if (!dict_content)
    {
        write(1, DICT_ERROR, ft_strlen(DICT_ERROR));
        return 1;
    }

    if (!is_valid_number(argv[argc - 1]))
    {
        write(1, ERROR, ft_strlen(ERROR));
        free(dict_content);
        return 1;
    }
    convert_to_words(argv[argc - 1], dict_content);
    free(dict_content);
    return 0;
}
