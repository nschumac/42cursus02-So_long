#ifndef SO_LONG_H
# define SO_LONG_H

/*
** INCLUDES, MACROS
*/
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <stdio.h>
# include "../mlx/mlx.h"
# include "../42cursus00-Libft/libft.h"
# include "../42cursus01-Get_next_line/get_next_line_bonus.h"

# define STEAM_RESOURCE "./resources/steam.xpm"
# define COIN_RESOURCE "./resources/coin.xpm"
# define EXIT_RESOURCE "./resources/exit.xpm"
# define WALL_RESOURCE "./resources/wall.xpm"
# define GRASS_RESOURCE "./resources/grass.xpm"

/*
** STRUCTS
*/
typedef struct s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_img
{
	void	*img;
	int		img_width;
	int		img_height;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_player
{
	unsigned int	coins;
	unsigned int	steps;
	int				pos[2];
	char			finished;
}				t_player;

typedef struct s_game
{
	t_img		*imgs[5];
	int			img_size;
	t_vars		vars;
	t_player	player;
	char		**map;
}				t_game;
/*
** KEYS
*/
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_F 3
# define KEY_H 4
# define KEY_G 5
# define KEY_Z 6
# define KEY_X 7
# define KEY_C 8
# define KEY_V 9
# define KEY_B 11
# define KEY_Q 12
# define KEY_W 13
# define KEY_E 14
# define KEY_R 15
# define KEY_Y 16
# define KEY_T 17
# define KEY_ONE 18
# define KEY_TWO 19
# define KEY_THREE 20
# define KEY_FOUR 21
# define KEY_SIX 22
# define KEY_FIVE 23
# define KEY_NINE 25
# define KEY_SEVEN 26
# define KEY_EIGHT 28
# define KEY_ZERO 29
# define KEY_BRACE_R 30
# define KEY_O 31
# define KEY_U 32
# define KEY_BRACE_L 33
# define KEY_I 34
# define KEY_P 35
# define KEY_L 37
# define KEY_J 38
# define KEY_K 40
# define KEY_SEMI 41
# define KEY_N 45
# define KEY_M 46
# define KEY_TAB 48
# define KEY_PLUS 69
# define KEY_MINUS 78
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126
# define KEY_ESC 0x35

/*
** FUNCS
*/
t_img	*ft_resize_img(t_img *org, t_vars *vars, int new);
char	ft_init(t_game *game, char *mappath);
int		ft_doparraysize(char **array);
char	ft_readmap(t_game *game, char *mappath);
void	ft_freeall(t_game *game, char img);
char	ft_makemove(int keycode, t_game *game);
#endif