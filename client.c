/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligabrie <ligabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 13:58:09 by ligabrie          #+#    #+#             */
/*   Updated: 2023/06/26 16:09:55 by ligabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdlib.h>

static volatile sig_atomic_t	g_receipt_received = 0;

void	receipt_handler(int sig)
{
	(void)sig;
	g_receipt_received = 1;
}

int	receipt(int *sa_return)
{
	while (!g_receipt_received)
	{
		if (sa_return == 0)
			return (g_receipt_received = 1);
		if (usleep(10000) == 0)
			ft_putstr_fd(", ", 1);
	}
	return (1);
}

void	send(int pid, unsigned char c, void *sa)
{
	int	sa_return;
	int	signal;
	int	i;

	i = 128;
	while (i > 0)
	{
		if (c >= i)
		{
			signal = SIGUSR2;
			c -= i;
		}
		else
			signal = SIGUSR1;
		if (kill(pid, signal) < 0)
			ft_putstr_fd("ERROR sending signal", 1);
		i = i / 2;
		sa_return = sigaction(SIGUSR1, sa, NULL);
		if (sa_return == -1)
			ft_putstr_fd("ERROR setting up receipt handler", 1);
		while (!receipt(&sa_return))
			usleep(10000);
		g_receipt_received = 0;
	}
}

void	serialize(int pid, unsigned char c)
{
	struct sigaction	sa;

	sa.sa_handler = receipt_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	send(pid, c, &sa);
}

int	main(int argc, char *argv[])
{
	int	server_pid;
	int	i;

	if (argc != 3)
	{
		ft_putstr_fd("ERROR: enter server pid and string to send", 1);
		return (-1);
	}
	server_pid = ft_atoi(argv[1]);
	i = -1;
	while (argv[2][++i])
	{
		serialize (server_pid, argv[2][i]);
	}
	serialize (server_pid, '\0');
	return (0);
}
