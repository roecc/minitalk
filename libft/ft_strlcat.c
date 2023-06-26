/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligabrie <ligabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:58:32 by ligabrie          #+#    #+#             */
/*   Updated: 2022/12/18 19:22:18 by ligabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t				i;
	long unsigned int	len;

	len = ft_strlen(dst);
	if (size > 0)
	{
		i = 0;
		while (i + len < size -1 && src[i] != '\0')
		{
			dst[i + len] = src[i];
			i++;
		}
		dst[i + len] = '\0';
	}
	if (size < len)
		len = size;
	return (ft_strlen((char *)src) + len);
}
