/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligabrie <ligabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:04:20 by ligabrie          #+#    #+#             */
/*   Updated: 2022/12/18 19:22:03 by ligabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	long unsigned int	i;
	long unsigned int	s1len;
	long unsigned int	s2len;
	char				*dest;	

	s1len = ft_strlen((char *)s1);
	s2len = ft_strlen((char *)s2);
	dest = (char *)malloc((s1len + s2len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	s1len = i;
	i = 0;
	while (s2[i] != '\0')
	{
		dest[i + s1len] = s2[i];
		i++;
	}
	dest[i + s1len] = '\0';
	return (dest);
}
