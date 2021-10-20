#include "../includes/so_long.h"

/*
** img = 0 if zou only wan tto destroy strings
*/
void	ft_freeall(t_game *game, char img)
{
	int	c;

	c = 0;
	while (img && ++c && c < 5)
	{
		if (game->imgs[c - 1])
		{
			mlx_destroy_image(game->vars.mlx, game->imgs[c - 1]->img);
			free(game->imgs[c - 1]);
		}
	}
	c = 0;
	while (++c && c < ft_doparraysize(game->map))
	{
		if (game->map[c - 1])
			free(game->map[c - 1]);
		game->map[c - 1] = NULL;
	}
	if (game->map)
		free(game->map);
	game->map = NULL;
	if (game->vars.win && img)
		mlx_destroy_window(game->vars.mlx, game->vars.win);
	exit(0);
}

static char	ft_makemovehelper(t_game *game, int *where)
{
	if (game->map[where[0]][where[1]] != '1')
	{
		if (game->map[where[0]][where[1]] == 'E')
			game->player.finished = 1;
		else
			game->map[where[0]][where[1]] = 'P';
		game->map[game->player.pos[0]][game->player.pos[1]] = '0';
		game->player.pos[0] = where[0];
		game->player.pos[1] = where[1];
		return (1);
	}
	return (0);
}

char	ft_makemove(int keycode, t_game *game)
{
	if (keycode == KEY_W && ft_makemovehelper(game,
			(int [2]){game->player.pos[0] - 1, game->player.pos[1]}))
		return (1);
	if (keycode == KEY_A && ft_makemovehelper(game,
			(int [2]){game->player.pos[0], game->player.pos[1] - 1}))
		return (1);
	if (keycode == KEY_D && ft_makemovehelper(game,
			(int [2]){game->player.pos[0], game->player.pos[1] + 1}))
		return (1);
	if (keycode == KEY_S && ft_makemovehelper(game,
			(int [2]){game->player.pos[0] + 1, game->player.pos[1]}))
		return (1);
	return (0);
}

int	ft_doparraysize(char **array)
{
	int	size;

	size = 0;
	if (!array)
		return (0);
	while (array[size])
		size++;
	return (size);
}
