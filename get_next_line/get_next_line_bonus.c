/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschumac <nschumac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 18:56:51 by nschumac          #+#    #+#             */
/*   Updated: 2021/07/07 19:28:32 by nschumac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_addstr(char **strorg, char *str, int count)
{
	char	*ret;

	ret = (char *)malloc(ft_strlensep(*strorg, '\0') + count + 1);
	ft_strcpycount(ret, *strorg, ft_strlensep(*strorg, '\0'));
	if (*strorg)
		free(*strorg);
	*strorg = 0;
	ft_strcpycount(ret + ft_strlensep(ret, '\0'), str, count);
	return (ret);
}

static char	ft_setrest(t_data *data, char **ret)
{
	int	count;

	if (!data->rest[data->fd])
		return (GNL_FALSE);
	count = 0;
	while (data->rest[data->fd][count])
	{
		if (data->rest[data->fd][count] == '\n')
		{
			*ret = ft_addstr(ret, data->rest[data->fd], count);
			ft_strcpycount(data->rest[data->fd],
				data->rest[data->fd] + count + 1,
				(ft_strlensep(data->rest[data->fd], '\0') - count));
			data->result = GNL_LINE_READ;
			return (GNL_TRUE);
		}
		count++;
	}
	if (data->rest[data->fd][0] != '\0')
		*ret = ft_addstr(ret, data->rest[data->fd], count);
	data->rest[data->fd][0] = 0;
	return (GNL_FALSE);
}

static char	*ft_getstr(t_data *data, char **line)
{
	int		count;

	while (1)
	{
		if (ft_setrest(data, line))
			return (*line);
		data->result = read(data->fd, data->newline[data->fd], BUFFER_SIZE);
		count = 0;
		if (data->result == GNL_ERROR || data->result == GNL_END_OF_FILE)
			return (*line);
		data->newline[data->fd][data->result] = 0;
		while (data->newline[data->fd][count] &&
			data->newline[data->fd][count] != '\n')
			count++;
		*line = ft_addstr(line, data->newline[data->fd], count);
		ft_strcpycount(data->rest[data->fd],
			data->newline[data->fd] + count + 1,
			data->result - count);
		if (data->newline[data->fd][count] == '\n')
			data->result = GNL_LINE_READ;
		if (data->newline[data->fd][count] == '\n')
			return (*line);
		data->newline[data->fd][0] = 0;
	}
}

int	ft_get_next_line(int fd, char **line)
{
	static t_data	data;

	data.fd = fd;
	if (fd < 0 || line == NULL)
		return (GNL_ERROR);
	if (!ft_initializedata(&data))
		return (GNL_ERROR);
	*line = (char *)malloc(1);
	if (!*line)
		return (GNL_ERROR);
	*line[0] = 0;
	*line = ft_getstr(&data, line);
	if (data.result == GNL_ERROR || *line == NULL)
	{
		if (*line)
			free(*line);
		*line = NULL;
		ft_freedata(&data);
	}
	if (data.result == GNL_END_OF_FILE)
		ft_freedata(&data);
	return (data.result);
}
