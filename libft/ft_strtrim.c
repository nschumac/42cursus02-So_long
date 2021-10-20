/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschumac <nschumac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 16:28:57 by nschumac          #+#    #+#             */
/*   Updated: 2021/06/24 19:27:55 by nschumac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	ft_ispartofset(const char c, const char *set)
{
	unsigned int	count;

	count = 0;
	while (set[count] != '\0')
	{
		if (set[count] == c)
			return (1);
		count++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	int		start;
	int		end;
	char	*ret;
	int		count;

	if (!s1 || !set)
		return (0);
	start = 0;
	while (s1[start] && ft_ispartofset(s1[start], set))
		start++;
	end = ft_strlen(s1) - 1;
	while (end > start && ft_ispartofset(s1[end], set))
		end--;
	ret = 0;
	ret = (char *)malloc(end - start + 2);
	if (!ret)
		return (ret);
	count = 0;
	while (count + start <= end && s1[count + start])
	{
		ret[count] = s1[count + start];
		count++;
	}
	ret[count] = '\0';
	return (ret);
}
