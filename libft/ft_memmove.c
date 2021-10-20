/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschumac <nschumac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 12:54:11 by nschumac          #+#    #+#             */
/*   Updated: 2021/06/23 13:54:03 by nschumac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			count;
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (!src && !dest)
		return (0);
	count = 0;
	if (src > dest)
	{
		while (++count && (count - 1) < n)
			*(d + (count - 1)) = *(s + (count - 1));
	}
	else
	{
		d += (n);
		s += (n);
		while (++count && count <= n)
			*(d - count) = *(s - count);
	}
	return (dest);
}
