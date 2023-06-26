/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligabrie <ligabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:37:20 by ligabrie          #+#    #+#             */
/*   Updated: 2022/12/18 19:22:38 by ligabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *s, int c)
{
	int			i;
	long int	len;

	len = ft_strlen(s);
	i = 0;
	while (i <= len)
	{
		if (s[len - i] == (char)c)
			return (&s[len - i]);
		i++;
	}
	return (NULL);
}
