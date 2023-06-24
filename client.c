/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 12:02:48 by kali              #+#    #+#             */
/*   Updated: 2023/06/24 13:52:05 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdlib.h>

void	serialize(int pid, char c)
{
	//8
	int	i = 128;
	while (i > 0)
	{
		if (c >= i)
		{
			kill(pid, SIGUSR2);
			c -= i;
		}
		else
			kill(pid, SIGUSR1);
		i = i/2;
		usleep(200);
	}
}

int	main (int argc, char *argv[])
{
	int	server_pid;

	server_pid = atoi(argv[1]);
	serialize (server_pid, argv[2][0]);

	return (0);
}