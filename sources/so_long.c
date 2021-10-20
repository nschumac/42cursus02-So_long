#include "../includes/so_long.h"

int	ft_whatimage(char c, t_game *game)
{
	if (c == 'C')
	{
		game->player.coins++;
		return (1);
	}
	else if (c == 'E')
		return (2);
	else if (c == 'P')
		return (0);
	else if (c == '0')
		return (4);
	else
		return (3);
}

static void	ft_drawgame(t_game *game)
{
	size_t	c_x;
	size_t	c_y;

	mlx_clear_window(game->vars.mlx, game->vars.win);
	c_x = 0;
	while (c_x < ft_strlen(game->map[0]))
	{
		c_y = 0;
		while (c_y < (size_t)ft_doparraysize(game->map))
		{
			if (game->map[c_y][c_x] == '1')
				mlx_put_image_to_window(game->vars.mlx, game->vars.win,
					game->imgs[3]->img,
					c_x * game->img_size, c_y * game->img_size);
			else
				mlx_put_image_to_window(game->vars.mlx,
					game->vars.win, game->imgs[4]->img,
					c_x * game->img_size, c_y * game->img_size);
			mlx_put_image_to_window(game->vars.mlx, game->vars.win,
				game->imgs[ft_whatimage(game->map[c_y][c_x], game)]->img,
				c_x * game->img_size, c_y * game->img_size);
			c_y++;
		}
		c_x++;
	}
}

int	ft_keyboardhook(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		ft_freeall(game, 1);
	if (game->player.finished)
		return (1);
	if (ft_makemove(keycode, game))
	{
		game->player.coins = 0;
		ft_drawgame(game);
		game->player.steps++;
		ft_putstr_fd("\r", 1);
		ft_putnbr_fd(game->player.steps, 1);
		if (game->player.finished && game->player.coins > 0)
			mlx_string_put(game->vars.mlx, game->vars.win,
				ft_strlen(game->map[0]) * game->img_size / 2 - 15,
				ft_doparraysize(game->map) * game->img_size / 2, 0xFFFFFFFF,
				"YOU FAILED TO COLLECT ALL COINS");
		else if (game->player.finished && game->player.coins == 0)
			mlx_string_put(game->vars.mlx, game->vars.win,
				ft_strlen(game->map[0]) * game->img_size / 2 - 8,
				ft_doparraysize(game->map) * game->img_size / 2, 0xFFFFFFFF,
				"YOU WIN BOIIII");
	}
	return (1);
}

int	ft_redcross(int keycode, t_game *game)
{
	if (keycode == KEY_S)
		game->map[0][0] = '0';
	exit(0);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
	{
		ft_putstr_fd("Error\n[INVALID ARGUMENT AMOUNT]\n", 2);
		return (-1);
	}
	game.vars.mlx = mlx_init();
	if (!ft_init(&game, argv[1]))
		return (-1);
	game.vars.win = mlx_new_window(game.vars.mlx,
			game.img_size * ft_strlen(game.map[0]),
			game.img_size * ft_doparraysize(game.map), "Steam Summersale");
	ft_drawgame(&game);
	mlx_hook(game.vars.win, 2, 1L << 0, ft_keyboardhook, &game);
	mlx_hook(game.vars.win, 17, 1L << 0, ft_redcross, &game);
	mlx_loop(game.vars.mlx);
	return (0);
}
