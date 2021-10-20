/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschumac <nschumac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 16:54:19 by nschumac          #+#    #+#             */
/*   Updated: 2021/06/23 13:56:25 by nschumac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	darraysize(char **arr)
{
	int				count;

	count = 0;
	while (arr[count] != 0)
		count++;
	return (count);
}

char	**copdarray(char **arr1, char *newstring)
{
	char			**buf;
	int				count;

	count = 0;
	buf = (char **)malloc((darraysize(arr1) + 2) * sizeof(char *));
	while (count < darraysize(arr1))
	{
		buf[count] = arr1[count];
		count++;
	}
	free(arr1);
	buf[count] = newstring;
	buf[count + 1] = 0;
	return (buf);
}

char	**ft_split(const char *s, char c)
{
	int				count;
	char			*buf;
	char			**ret;
	char			*new;

	count = 0;
	ret = (char **)malloc(sizeof(char *));
	if (!ret || !s)
		return (0);
	ret[0] = 0;
	while (s[count] != '\0')
	{
		if (s[count] != c)
		{
			buf = (char *)&s[count];
			while (s[count] != '\0' && s[count] != c)
				count++;
			new = (char *)malloc(&s[count] - buf + 1);
			ft_strlcpy(new, buf, &s[count] - buf + 1);
			ret = copdarray(ret, new);
		}
		else
			count++;
	}
	return (ret);
}
