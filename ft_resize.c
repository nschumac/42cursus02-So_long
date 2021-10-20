#include "so_long.h"

static void	ft_putpixelimg(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static float	ft_cutfloat(float num)
{
	int	buf;

	buf = num * 10;
	return ((float)buf / 10.0f);
}

static void	ft_downscale(t_img *ret, t_img *org, float scale)
{
	int				c_x;
	int				c_y;
	unsigned int	color;

	c_x = 0;
	while (c_x < ret->img_width)
	{
		c_y = 0;
		while (c_y < ret->img_height)
		{
			color = *(unsigned int *)(org->addr
					+ (unsigned int)(c_y * org->line_length * scale
						+ c_x * scale * (org->bits_per_pixel / 8)));
			ft_putpixelimg(ret, c_x, c_y, color);
			c_y++;
		}
		c_x++;
	}
}

t_img	*ft_resize_img(t_img *org, t_vars *vars, int new)
{
	t_img	*ret;
	float	new_scale;

	ret = (t_img *)malloc(sizeof(t_img));
	new_scale = ft_cutfloat(new / org->img_width);
	ret->img = mlx_new_image(vars->mlx, new, new);
	ret->img_height = new;
	ret->img_width = new;
	ret->addr = mlx_get_data_addr(ret->img,
			&ret->bits_per_pixel, &ret->line_length,
			&ret->endian);
	org->addr = mlx_get_data_addr(org->img,
			&org->bits_per_pixel, &org->line_length,
			&org->endian);
	if (new_scale < 1.f)
		ft_downscale(ret, org, org->img_width / new);
	return (ret);
}
