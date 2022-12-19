/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:34:23 by lpupier           #+#    #+#             */
/*   Updated: 2022/11/24 10:38:32 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *count)
{
	if (*count == -1)
		return ;
	if (write(1, &c, 1) != -1)
		*count = *count + 1;
	else
		*count = -1;
}

void	ft_putstr(char *str, int *count)
{
	int	idx;

	idx = 0;
	if (!str)
		return (ft_putstr("(null)", count));
	while (str[idx])
	{
		ft_putchar(str[idx], count);
		idx++;
	}
}
