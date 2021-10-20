#include "so_long.h"

static char	ft_validppath(char *path)
{
	if (ft_strlen(path) < 4)
		return (0);
	if (ft_strncmp(&path[ft_strlen(path) - 4], ".ber", 10000))
		return (0);
	return (1);
}

static char	ft_darrayappend(char ***darray, char *newstring)
{
	char			**buf;
	int				count;

	count = 0;
	buf = (char **)malloc((ft_doparraysize(*darray) + 2) * sizeof(char *));
	if (!buf)
		return (0);
	while (count < ft_doparraysize(*darray))
	{
		buf[count] = (*darray)[count];
		count++;
	}
	free(*darray);
	buf[count] = newstring;
	buf[count + 1] = 0;
	*darray = buf;
	return (1);
}

static char	ft_strnchr(int strindex, char *set, char *status, t_game *game)
{
	int	count;

	count = 0;
	while (game->map[strindex][count])
	{
		if (!ft_strchr(set, game->map[strindex][count]))
			return (0);
		if (game->map[strindex][count] == 'E')
			status[0]++;
		if (game->map[strindex][count] == 'C')
			status[1]++;
		if (game->map[strindex][count] == 'P')
		{
			game->player.pos[0] = strindex;
			game->player.pos[1] = count;
			status[2]++;
		}
		count++;
	}
	return (1);
}

static char	ft_validate(t_game *game)
{
	int		count;
	int		strlen_old;
	int		curlen;
	char	status[3];

	ft_bzero(status, 3);
	count = 0;
	while (count < ft_doparraysize(game->map))
	{
		curlen = ft_strlen(game->map[count]);
		if (count == 0 || count == ft_doparraysize(game->map) - 1)
			if (!ft_strnchr(count, "1", (char *)status, game))
				return (0);
		if (!ft_strnchr(count, "10ECP", (char *)status, game))
			return (0);
		if (game->map[count][0] != '1' || game->map[count][curlen - 1] != '1')
			return (0);
		if (count > 0 && strlen_old != curlen)
			return (0);
		strlen_old = curlen;
		count++;
	}
	if (!status[0] || !status[1] || status[2] != 1)
		return (0);
	return (1);
}

char	ft_readmap(t_game *game, char *mappath)
{
	char	*buf;
	int		fd;

	game->map = (char **)malloc(sizeof(char *));
	if (!game->map[0])
		return (0);
	game->map[0] = NULL;
	if (!ft_validppath(mappath))
		return (0);
	fd = open(mappath, O_RDONLY);
	if (fd < 0)
		return (0);
	while (ft_get_next_line(fd, &buf))
	{
		if (!ft_darrayappend(&game->map, buf))
			return (0);
		buf = NULL;
	}
	if (!ft_darrayappend(&game->map, buf))
		return (0);
	buf = NULL;
	close(fd);
	return (ft_validate(game));
}
