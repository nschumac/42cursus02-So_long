/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschumac <nschumac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 10:50:40 by nschumac          #+#    #+#             */
/*   Updated: 2021/06/24 18:11:51 by nschumac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

char	ft_printzero(long num, int fd)
{
	if (num == 0)
	{
		write(fd, "0", 1);
		return (1);
	}
	return (0);
}

void	ft_putnbr_fd(int n, int fd)
{
	long		num;
	char		buf[10];
	int			count;

	num = n;
	if (ft_printzero(num, fd))
		return ;
	if (num < 0)
	{
		write(fd, "-", 1);
		num *= -1;
	}
	count = 9;
	while (num > 0)
	{
		buf[count] = num % 10 + '0';
		num /= 10;
		count--;
	}
	while (count < 9)
	{
		count++;
		write(fd, &buf[count], 1);
	}
}
