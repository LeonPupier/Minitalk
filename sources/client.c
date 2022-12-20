/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:43:53 by lpupier           #+#    #+#             */
/*   Updated: 2022/12/20 12:42:41 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minitalk.h"

static void	send_bit(pid_t pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (1 << bit)) != 0)
		{
			if (kill(pid, SIGUSR1) < 0)
				exit(1);
		}
		else
		{
			if (kill(pid, SIGUSR2) < 0)
				exit(1);
		}
		usleep(45);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		idx;
	char	*str;

	ft_printf("\033[07m[CLIENT LOGS]\033[00m\n");
	if (argc != 3)
	{
		ft_printf("\033[31m[ERROR]\033[00m	Bad arguments.\n");
		return (EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	if (pid == 0)
	{
		ft_printf("\033[31m[ERROR]\033[00m	Bad PID.\n");
		return (EXIT_FAILURE);
	}
	str = argv[2];
	idx = 0;
	while (str[idx])
	{
		send_bit(pid, str[idx]);
		idx++;
	}
	send_bit(pid, '\0');
	return (EXIT_SUCCESS);
}
