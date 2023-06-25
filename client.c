/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligabrie <ligabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 12:02:48 by kali              #+#    #+#             */
/*   Updated: 2023/06/25 19:48:38 by ligabrie         ###   ########.fr       */
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
		usleep(350);
	}
}

int	main (int argc, char *argv[])
{
	int	server_pid;
	int	i;

	if (argc != 3)
		return(-1);

	server_pid = ft_atoi(argv[1]);

	i = -1;
	while (argv[2][++i])
	{
		serialize (server_pid, argv[2][i]);
		//usleep (840);
	}
	serialize (server_pid, '\0');
	return (0);
}