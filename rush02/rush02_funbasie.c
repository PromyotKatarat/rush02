/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02_funbasie.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuksarn <psuksarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 10:43:20 by psuksarn          #+#    #+#             */
/*   Updated: 2024/12/07 12:59:17 by psuksarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return (i);
}

char *ft_strdup(char *str)
{
    char *result;
    int i;

    result = (char *)malloc(ft_strlen(str) + 1);
    i = 0;
    if (result == NULL)
        return (NULL);
    while (str[i] != 0)
    {
        result[i] = str[i];
        i++;
    }
    result[i] = '\0';
    return (result);
}

int ft_strncmp(char *dest, char *str, int nbr)
{
    int i;

    i = 0;
    while (i < nbr)
    {
        if (dest[i] != str[i])
            return (1);
        i++;
    }
    return (0);
}
