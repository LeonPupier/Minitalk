/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:39:41 by lpupier           #+#    #+#             */
/*   Updated: 2022/12/20 13:04:50 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minitalk.h"

// Global variable: String list for character storage
t_list	*g_str;

static void	display(void)
{
	t_list	*temp;

	if (g_str)
	{
		temp = g_str;
		g_str = g_str->next;
		display();
		write(1, &temp->content, 1);
		free(temp);
	}
}

static void	add_char(char c)
{
	t_list	*new;

	new = ft_lstnew(c);
	ft_lstadd_front(&g_str, new);
}

static void	ft_sigusr1(int code)
{
	static int		bit;
	static int		c;

	if (code == SIGUSR1)
		c = c | (1 << bit);
	bit++;
	if (bit == 8)
	{
		if (c == '\0')
		{
			display();
			ft_lstclear(&g_str);
			g_str = NULL;
		}
		else
			add_char(c);
		c = 0;
		bit = 0;
	}
}

int	main(void)
{
	ft_printf("\033[07m[SERVER LOGS]\033[00m\n");
	if (signal(SIGUSR1, ft_sigusr1) >= 0 && signal(SIGUSR2, ft_sigusr1) >= 0)
	{
		ft_printf("\033[32m[INFO]\033[00m	PID: %d\n", getpid());
		ft_printf("\033[32m[INFO]\033[00m	Waiting...\n");
		g_str = NULL;
		while (1)
			pause();
		return (EXIT_SUCCESS);
	}
	else
	{
		ft_printf("\033[31m[ERROR]\033[00m	Signal problem.\n");
		return (EXIT_FAILURE);
	}
}
