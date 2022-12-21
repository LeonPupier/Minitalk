/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:43:53 by lpupier           #+#    #+#             */
/*   Updated: 2022/12/21 10:45:54 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Headers
#include "../headers/minitalk.h"

/**
 * @brief Function to send to the server each character
 * of a string broken down into bits.
 * 
 * @param pid PID of the server to send the character in bit shifting.
 * @param c Character of a string to be sent to the server.
 */
static void	send_bit(pid_t pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < BYTE_SIZE)
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
		usleep(SLEEP_TIME);
		bit++;
	}
}

/**
 * @brief Program the body, initialize the client and
 * send the signal to the server.
 * 
 * @param argc Number of arguments provided at the launch of the program.
 * @param argv List of argument strings supplied to the program.
 * @return int The end status of the server with the
 * EXIT_SUCCESS or EXIT_FAILURE macros.
 */
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
