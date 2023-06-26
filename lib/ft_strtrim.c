/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligabrie <ligabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:39:42 by ligabrie          #+#    #+#             */
/*   Updated: 2022/12/18 19:22:42 by ligabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	inset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (!inset(s1[i], set))
			break ;
		i++;
	}
	start = i;
	while (s1[i] != '\0')
		i++;
	i--;
	while (i >= 0)
	{
		if (!inset(s1[i], set))
			break ;
		i--;
	}
	return (ft_substr(s1, start, (i - start + 1)));
}
