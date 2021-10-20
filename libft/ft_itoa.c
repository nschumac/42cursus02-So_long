/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschumac <nschumac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 18:02:46 by nschumac          #+#    #+#             */
/*   Updated: 2021/06/22 14:05:02 by nschumac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_abs(int num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}

char	*ft_handlezero(void)
{
	char	*ret;

	ret = (char *)malloc(2);
	if (!ret)
		return (0);
	ret[0] = '0';
	ret[1] = '\0';
	return (ret);
}

char	*ft_itoa(int n)
{
	int		length;
	long	num;
	char	*yeet;

	if (n == 0)
		return (ft_handlezero());
	length = 1;
	num = n / 10;
	while (num != 0 && length++)
		num /= 10;
	if (n < 0)
		length++;
	yeet = (char *)malloc(length + 1);
	if (!yeet)
		return (0);
	if (n < 0)
		yeet[0] = '-';
	yeet[length] = '\0';
	while (n != 0)
	{
		yeet[--length] = ft_abs(n % 10) + '0';
		n /= 10;
	}
	return (yeet);
}
