/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 11:54:51 by kali              #+#    #+#             */
/*   Updated: 2023/06/24 19:00:51 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	deserialize (char *str)
{
	int	i;
	char	c;
	int	pwr;

	pwr = 128;
	i = -1;
	while (++i < 8)
	{
		c += (str[i] - '0') * pwr;
		pwr = pwr/2;
	}
	printf ("%c", c);
	if (c == '\0')
		printf ("\n");
}

void	buffer (char c)
{
	static char	*bin;
	int	i;
	if (!bin)
	{
		bin = (char *)malloc(sizeof(char) * 9);
		ft_bzero(bin, 8);
		bin[8] = '\0';
	}
	if (!bin)
		return;
	i = 0;
	while (bin[i] && bin[i] != '2')
		i++;
	bin[i] = c;
	if (++i == 8)
	{
		deserialize(bin);
		ft_bzero(bin, 8);
		//free(bin);
	}
}

void	sigusr1_handler ()
{
	buffer('0');
}

void	sigusr2_handler ()
{
	buffer('1');
}

void	write_pid(int pid)
{
    FILE *file = fopen("pid.txt", "w");  // Open the file in write mode

    if (file)
    {
        // Write content to the file
        fprintf(file, ft_itoa(pid));

        fclose(file);  // Close the file
    }
    else
    {
        printf("Failed to create or open the file.\n");
    }
}

int	main (int argc, char *argv[])
{
	int	pid;

	signal(SIGUSR1, sigusr1_handler);
	signal(SIGUSR2, sigusr2_handler);
	pid = getpid();
	printf("pid: %d", pid);
	write_pid(pid);
	//printf() writes to stdout (the default output stream) which is usually line buffered. The buffer isn't flushed by the time sleep is called so nothing is displayed
	// if stdout is redirected or you are writing to a file, simply printing a newline probably won't work. In such cases you should use fflush if you want the data written immediately
	printf("\n");
	while (1)
		pause();
	return (0);
}