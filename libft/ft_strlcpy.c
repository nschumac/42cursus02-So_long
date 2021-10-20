/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschumac <nschumac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 12:54:48 by nschumac          #+#    #+#             */
/*   Updated: 2021/06/23 13:58:33 by nschumac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	count;

	if (!dest)
		return (0);
	count = 0;
	while (count + 1 < n && src[count])
	{
		dest[count] = src[count];
		count++;
	}
	if (n)
		dest[count] = '\0';
	return (ft_strlen(src));
}
