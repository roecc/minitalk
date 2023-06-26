/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligabrie <ligabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 11:54:51 by kali              #+#    #+#             */
/*   Updated: 2023/06/26 12:07:12 by ligabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	deserialize (int b)
{
	static int	pwr_and_c[2];

	if (b == -1)
	{
		pwr_and_c[0] = 128;
		pwr_and_c[1] = 0;
		return;
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
	}
}
/*
void	deserialize (char *str)
{
	int	i;
	char	c;
	int	pwr;

	c = 0;
	pwr = 128;
	i = -1;
	while (++i < 8)
	{
		c += (str[i] - '0') * pwr;
		pwr = pwr/2;
	}
	write(1, &c, 1);
	if (c == '\0')
		write(1, "\n", 1);
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
	}
}
*/
void	sigusr1_handler ()
{
	//buffer('0');
	deserialize(0);
}

void	sigusr2_handler ()
{
	//uffer('1');
	deserialize(1);
}

/*void	write_pid(int pid)
{
    FILE *file = fopen("pid.txt", "w");  // Open the file in write mode

    if (file)
    {
        // Write content to the file
        fprintf(file, "%s", ft_itoa(pid));

        fclose(file);  // Close the file
    }
    else
    {
        printf("Failed to create or open the file.\n");
    }
}*/

int	main ()
{
	int	pid;

	signal(SIGUSR1, sigusr1_handler);
	signal(SIGUSR2, sigusr2_handler);
	pid = getpid();
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	deserialize (-1);
	while (1)
		pause();
	return (0);
}