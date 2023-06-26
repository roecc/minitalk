/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligabrie <ligabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:26:03 by ligabrie          #+#    #+#             */
/*   Updated: 2022/12/18 19:20:44 by ligabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	getlen(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n = n * -1;
		len++;
	}
	while (n > 9)
	{
		len++;
		n = n / 10;
	}
	len++;
	return (len);
}

static char	*writestr(char *dest, int len, int strlen, int n)
{
	int	i;

	i = 0;
	while (i < len)
	{
		dest[strlen - i - 1] = n % 10 + '0';
		n = n / 10;
		i++;
	}
	return (dest);
}

char	*ft_itoa(int n)
{
	char	*dest;
	int		i;
	int		len;
	int		strlen;

	i = 0;
	if (n == -2147483648)
	{
		return (ft_strdup("-2147483648\0"));
	}
	if (n < 0)
	{
		n = n * -1;
		i = 1;
	}
	len = getlen(n);
	strlen = len + i;
	dest = malloc(sizeof(char) * (strlen + 1));
	if (!dest)
		return (NULL);
	if (i == 1)
		dest[0] = '-';
	dest = writestr(dest, len, strlen, n);
	dest[strlen] = '\0';
	return (dest);
}
