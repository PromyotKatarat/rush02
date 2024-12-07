/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuksarn <psuksarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 20:09:16 by psuksarn          #+#    #+#             */
/*   Updated: 2024/12/07 12:29:52 by psuksarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	ft_atoi(char *str)
{
	int		sign;
	int		result;
	int		i;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13))
	{
		i++;
	}
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
		{
			sign *= -1;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
// int main()
// {
//     const char strg[] = "---+--+66898";
//     int value = ft_atoi(&strg);

//     // print the Converted Value
//     printf("String to be Converted: %s\n", strg);
//     printf("Converted to Integer: %d\n", value);
//     return 0;
// 