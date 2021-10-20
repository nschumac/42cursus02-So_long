/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschumac <nschumac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 14:28:48 by nschumac          #+#    #+#             */
/*   Updated: 2021/06/19 15:10:41 by nschumac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		count;
	long	number;
	int		minus;

	number = 0;
	count = 0;
	while (str[count] != '\0' && isspace(str[count]))
		count++;
	minus = 1;
	if (str[count] == '-' || str[count] == '+')
	{
		if (str[count] == '-')
			minus = -1;
		count++;
	}
	while (str[count] >= '0' && str[count] <= '9')
	{
		number += str[count] - '0';
		count++;
		if (str[count] >= '0' && str[count] <= '9')
			number *= 10;
	}
	return (minus * number);
}
