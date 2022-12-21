/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:19:49 by lpupier           #+#    #+#             */
/*   Updated: 2022/12/21 10:29:57 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Headers
#include "../headers/minitalk.h"

/**
 * @brief Atoi overflow check function for the sign.
 * 
 * @param sign Sign of atoi conversion detected.
 * @return int Returns 1 or -1 depending on the sign of the overflow function.
 */
static int	ft_check_overflow(int sign)
{
	if (sign == -1)
		return (0);
	return (-1);
}

/**
 * @brief Conversion function if the final integer exceeds the overflow.
 * 
 * @param res Integer just converted to return.
 * @return long long int Returns the integer subject to the overflow test.
 */
static long long int	ft_conv(long long int res)
{
	if (res > INT_MAX)
		return (res - LLONG_MAX - 1);
	else if (res < INT_MIN)
		return (res - LLONG_MIN);
	else
		return (res);
}

/**
 * @brief Function allowing to cover a character string in an integer.
 * 
 * @param str String to convert to integer.
 * @return int Integer resulting from the conversion from the character string.
 */
int	ft_atoi(const char *str)
{
	long long int	result;
	int				idx;
	int				sign;

	result = 0;
	idx = 0;
	sign = 1;
	while (str[idx] == ' ' || (str[idx] >= 9 && str[idx] <= 13))
		idx++;
	if (str[idx] == '+' || str[idx] == '-')
	{	
		if (str[idx] == '-')
			sign = -1;
		idx++;
	}
	while (str[idx] && str[idx] >= '0' && str[idx] <= '9')
	{
		if (result != ((result * 10 + (str[idx] - 48)) / 10))
			return (ft_check_overflow(sign));
		result = result * 10 + str[idx] - 48;
		idx++;
	}
	return ((int)ft_conv(result * sign));
}
