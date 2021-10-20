/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschumac <nschumac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 21:05:50 by nschumac          #+#    #+#             */
/*   Updated: 2021/06/18 16:09:52 by nschumac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*lstbuf;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		lstbuf = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = lstbuf;
	}
	lst = 0;
}
