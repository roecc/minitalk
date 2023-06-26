/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligabrie <ligabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 13:58:03 by ligabrie          #+#    #+#             */
/*   Updated: 2023/06/26 14:18:57 by ligabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	deserialize(int b)
{
	static int	pwr_and_c[2];

	if (b == -1)
	{
		pwr_and_c[0] = 128;
		pwr_and_c[1] = 0;
		return (-1);
	}
	pwr_and_c[1] += pwr_and_c[0] * b;
	pwr_and_c[0] = pwr_and_c[0] / 2;
	if (pwr_and_c[0] < 1)
	{
		if (pwr_and_c[1] == '\0')
			write(1, "\n", 1);
		else
			write(1, &pwr_and_c[1], 1);
		pwr_and_c[0] = 128;
		pwr_and_c[1] = 0;
		return (1);
	}
	return (1);
}

void	sig_handler(int signal, siginfo_t *info, void *stuff)
{
	int	done;

	(void) stuff;
	if (signal == SIGUSR1 || signal == SIGUSR2)
	{
		done = 0;
		if (signal == SIGUSR1)
			done = deserialize(0);
		else if (signal == SIGUSR2)
			done = deserialize(1);
		if (done)
			kill(info->si_pid, SIGUSR1);
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	sa.sa_sigaction = &sig_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	deserialize (-1);
	while (1)
		pause();
	return (0);
}
