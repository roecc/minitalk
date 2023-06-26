/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligabrie <ligabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 22:25:24 by admin             #+#    #+#             */
/*   Updated: 2022/12/18 14:17:01 by ligabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*loc;

	loc = (void *)malloc(count * size);
	if (!loc)
		return (loc);
	ft_bzero(loc, size * count);
	return (loc);
}
