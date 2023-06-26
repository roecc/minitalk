/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligabrie <ligabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:04:58 by ligabrie          #+#    #+#             */
/*   Updated: 2022/12/18 19:24:44 by ligabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	countseg(char const *s, char c)
{
	size_t	i;
	size_t	segnum;
	int		trig;

	i = 0;
	segnum = 1;
	trig = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && trig == 0)
		{
			segnum++;
			trig = 1;
		}
		else if (s[i] == c)
			trig = 0;
		i++;
	}
	return (segnum);
}

static char	*segment(char const *s, char c)
{
	char	*dest;
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	dest = (char *)malloc(i + 1 * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	size_t	segnum;
	int		trig;
	char	**dest;

	if (!s)
		return (NULL);
	dest = (char **)malloc((countseg(s, c) + 1) * sizeof(char *));
	if (!dest)
		return (NULL);
	trig = 0;
	segnum = 0;
	while (*s)
	{
		if (*s != c && trig == 0)
		{
			dest[segnum] = segment(s, c);
			segnum++;
			trig = 1;
		}
		else if (*s == c)
			trig = 0;
		s++;
	}
	dest[segnum] = NULL;
	return (dest);
}
