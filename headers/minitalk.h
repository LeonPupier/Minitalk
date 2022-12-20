/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:01:18 by lpupier           #+#    #+#             */
/*   Updated: 2022/12/20 12:38:23 by lpupier          ###   ########.fr       */
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

// Structure
typedef struct s_list
{
	char			content;
	struct s_list	*next;
}	t_list;

// ft_atoi.c
int		ft_atoi(const char *str);

// lst.c
t_list	*ft_lstnew(char content);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);

#endif