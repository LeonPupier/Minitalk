/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:39:41 by lpupier           #+#    #+#             */
/*   Updated: 2022/12/19 14:03:20 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minitalk.h"

static size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

static char	*display_str(char *str)
{
	ft_printf("\033[93m[TEXT]\033[00m	%s\n", str);
	free(str);
	return (NULL);
}

static char	*add_char(char c, char *str)
{
	size_t	len;
	int		idx;
	char	*new_str;

	len = ft_strlen(str);
	new_str = malloc(sizeof(char) * (len + 2));
	if (!new_str)
		return (free(str), NULL);
	idx = 0;
	while (str[idx])
	{
		new_str[idx] = str[idx];
		idx++;
	}
	new_str[idx] = c;
	new_str[idx + 1] = '\0';
	free(str);
	return (new_str);
}

static void	ft_sigusr1(int code)
{
	static int	bit;
	static int	c;
	static char	*str;

	if (str == NULL)
	{
		str = malloc(sizeof(char));
		if (!str)
			return ;
		str[0] = '\0';
	}
	if (code == SIGUSR1)
		c = c | (1 << bit);
	bit++;
	if (bit == 8)
	{
		if (c == '\0')
			str = display_str(str);
		else
			str = add_char(c, str);
		c = 0;
		bit = 0;
	}
}

int	main(void)
{
	ft_printf("\033[07m[SERVER LOGS]\033[00m\n");
	ft_printf("\033[32m[INFO]\033[00m	PID: %d\n", getpid());
	ft_printf("\033[32m[INFO]\033[00m	Waiting...\n");
	signal(SIGUSR1, ft_sigusr1);
	signal(SIGUSR2, ft_sigusr1);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
