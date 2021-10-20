/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschumac <nschumac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 12:53:20 by nschumac          #+#    #+#             */
/*   Updated: 2021/06/24 17:45:35 by nschumac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t n)
{
	size_t			count;
	unsigned char	*ptr1_buffer;
	unsigned char	*ptr2_buffer;

	ptr1_buffer = (unsigned char *)ptr1;
	ptr2_buffer = (unsigned char *)ptr2;
	count = 0;
	while (count < n)
	{
		if (*(ptr1_buffer + count)
			!= *(ptr2_buffer + count))
			return (*(ptr1_buffer + count) - *(ptr2_buffer + count));
		count++;
	}
	return (0);
}
