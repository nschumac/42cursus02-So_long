/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschumac <nschumac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 18:56:42 by nschumac          #+#    #+#             */
/*   Updated: 2021/07/02 19:42:08 by nschumac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlensep(char *str, char seperator)
{
	size_t	size;

	size = 0;
	while (str && str[size] != seperator)
		size++;
	return (size);
}

void	ft_strcpycount(char *str1, char *str2, int c)
{
	int	count;

	count = 0;
	if (!str1 || !str2)
		return ;
	while (count < c && str2[count] != '\0')
	{
		str1[count] = str2[count];
		count++;
	}
	str1[count] = '\0';
}

void	ft_freedata(t_data *data)
{
	if (data->newline[data->fd])
		free(data->newline[data->fd]);
	data->newline[data->fd] = 0;
	if (data->rest[data->fd])
		free(data->rest[data->fd]);
	data->rest[data->fd] = 0;
	data->initialized[data->fd] = GNL_FALSE;
}

int	ft_initializedata(t_data *data)
{
	if (data->initialized[data->fd] == GNL_TRUE)
		return (GNL_TRUE);
	data->initialized[data->fd] = GNL_TRUE;
	data->result = 0;
	data->newline[data->fd] = (char *)malloc(BUFFER_SIZE + 1);
	if (!data->newline[data->fd])
		return (GNL_FALSE);
	data->newline[data->fd][0] = 0;
	data->rest[data->fd] = (char *)malloc(BUFFER_SIZE + 1);
	if (!data->rest[data->fd])
		return (GNL_FALSE);
	data->rest[data->fd][0] = 0;
	return (GNL_TRUE);
}
