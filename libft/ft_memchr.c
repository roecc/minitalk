/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligabrie <ligabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:02:59 by ligabrie          #+#    #+#             */
/*   Updated: 2022/12/18 19:20:52 by ligabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *s, int c, size_t n)
{
	unsigned char	uc;
	size_t			i;

	uc = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == uc)
		{
			return (&s[i]);
		}
		i++;
	}
	return (NULL);
}
