/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_condition.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:11:45 by lquehec           #+#    #+#             */
/*   Updated: 2023/08/20 15:13:00 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	ft_is_whitespace(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int	ft_is_number(char c)
{
	return (c >= '0' && c <= '9');
}
