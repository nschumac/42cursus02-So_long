#include "../includes/so_long.h"

static char	ft_loadimages(t_game *game)
{
	t_img	buf;

	buf.img = mlx_xpm_file_to_image(game->vars.mlx, STEAM_RESOURCE,
			&buf.img_height, &buf.img_width);
	game->imgs[0] = ft_resize_img(&buf, &game->vars, game->img_size);
	mlx_destroy_image(game->vars.mlx, buf.img);
	buf.img = mlx_xpm_file_to_image(game->vars.mlx, COIN_RESOURCE,
			&buf.img_height, &buf.img_width);
	game->imgs[1] = ft_resize_img(&buf, &game->vars, game->img_size);
	mlx_destroy_image(game->vars.mlx, buf.img);
	buf.img = mlx_xpm_file_to_image(game->vars.mlx, EXIT_RESOURCE,
			&buf.img_height, &buf.img_width);
	game->imgs[2] = ft_resize_img(&buf, &game->vars, game->img_size);
	mlx_destroy_image(game->vars.mlx, buf.img);
	buf.img = mlx_xpm_file_to_image(game->vars.mlx, WALL_RESOURCE,
			&buf.img_height, &buf.img_width);
	game->imgs[3] = ft_resize_img(&buf, &game->vars, game->img_size);
	mlx_destroy_image(game->vars.mlx, buf.img);
	buf.img = mlx_xpm_file_to_image(game->vars.mlx, GRASS_RESOURCE,
			&buf.img_height, &buf.img_width);
	game->imgs[4] = ft_resize_img(&buf, &game->vars, game->img_size);
	mlx_destroy_image(game->vars.mlx, buf.img);
	return (1);
}

char	ft_init(t_game *game, char *mappath)
{
	game->img_size = 128;
	game->player.steps = 0;
	game->player.finished = 0;
	game->player.pos[0] = 0;
	game->player.pos[1] = 0;
	if (!ft_readmap(game, mappath))
	{
		ft_putstr_fd("Error\n[FAILED TO LOAD MAP]\n", 2);
		ft_freeall(game, 1);
		return (0);
	}
	while (game->img_size * ft_strlen(game->map[0]) > 2560
		|| game->img_size * ft_doparraysize(game->map) > 1440)
		game->img_size /= 2;
	if (!ft_loadimages(game))
	{
		ft_putstr_fd("Error\n[FAILED TO LOAD IMAGES]\n", 2);
		ft_freeall(game, 1);
		return (0);
	}
	return (1);
}
