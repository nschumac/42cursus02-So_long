/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschumac <nschumac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 15:09:19 by nschumac          #+#    #+#             */
/*   Updated: 2021/06/18 13:49:45 by nschumac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *str)
{
	char	*copy;
	int		c;

	c = 0;
	while (str[c] != '\0')
		c++;
	copy = 0;
	copy = (char *)malloc(c + 1);
	if (!copy)
		return (0);
	c = 0;
	while (str[c] != '\0')
	{
		copy[c] = str[c];
		c++;
	}
	copy[c] = str[c];
	return (copy);
}
