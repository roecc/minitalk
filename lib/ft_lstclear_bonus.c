/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligabrie <ligabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 20:54:18 by ligabrie          #+#    #+#             */
/*   Updated: 2022/12/18 21:08:23 by ligabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	size_t	i;
	t_list	*tmp;
	t_list	*nxt;

	if (!*lst)
		return ;
	i = 0;
	tmp = *lst;
	while (tmp->next)
	{
		nxt = tmp->next;
		ft_lstdelone(tmp, del);
		tmp = nxt;
	}
	ft_lstdelone(tmp, del);
	*lst = NULL;
}
