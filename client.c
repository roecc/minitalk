/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 12:02:48 by kali              #+#    #+#             */
/*   Updated: 2023/06/24 19:11:46 by kali             ###   ########.fr       */
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
		usleep(250);
	}
}

int	read_pid ()
{
	int number;
	
	FILE *file = fopen("pid.txt", "r");  // Open the file in read mode

    if (file != NULL)
    {
        char line[100];
        if (fgets(line, sizeof(line), file) != NULL)  // Read the first line of the file
        	number = atoi(line);  // Convert the line to an integer

        fclose(file);  // Close the file
    }
	return number;
}

int	main (int argc, char *argv[])
{
	int	server_pid;
	int	i;

	server_pid = read_pid(); //atoi(argv[1]);

	i = -1;
	while (argv[1][++i])
	{
		serialize (server_pid, argv[1][i]);
		usleep (2500);
	}
	serialize (server_pid, '\0');
	return (0);
}