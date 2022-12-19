/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:01:18 by lpupier           #+#    #+#             */
/*   Updated: 2022/12/19 13:04:47 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

// Librairies
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include "../ft_printf/ft_printf.h"

# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1

// ft_atoi.c
int		ft_atoi(const char *str);

#endif