
#include "miniRT.h"

static void	camera_adj(mlx_key_data_t key, t_data *id)
{
	if (key.key == MLX_KEY_LEFT)
		id->temp.x -= 0.1;
	if (key.key == MLX_KEY_RIGHT)
		id->temp.x += 0.1;
	if (key.key == MLX_KEY_UP)
		id->temp.y -= 0.1;
	if (key.key == MLX_KEY_DOWN)
		id->temp.y += 0.1;
	if (key.key == MLX_KEY_Q)
		id->temp.z += 0.1;
	if (key.key == MLX_KEY_W)
		id->temp.z -= 0.1;
	if (key.key == MLX_KEY_A)
		id->di.x += 0.01;
	if (key.key == MLX_KEY_S)
		id->di.x -= 0.01;
}

void	hook(mlx_key_data_t key, void *param)
{
	t_data	*id;

	id = (t_data *)param;
	if (key.key == MLX_KEY_ESCAPE && key.action == MLX_PRESS)
	{
		ft_putstr_fd("ESC end miniRT\n", 2);
		mlx_delete_texture(id->b_texture);
		mlx_delete_image(id->mlx, id->img);
		mlx_delete_image(id->mlx, id->status_bar);
		mlx_terminate(id->mlx);
		free_success(id);
		exit(EXIT_SUCCESS);
	}
	if (key.key == MLX_KEY_C && key.action == MLX_PRESS)
		id->checker_board = (id->checker_board + 1) % 2;
	if (key.key == MLX_KEY_B && key.action == MLX_PRESS)
		id->bump_map = (id->bump_map + 1) % 2;
	camera_adj(key, id);
}

void	status_bar(t_data *id)
{
	int			i[2];

	id->status_bar = mlx_new_image(id->mlx, 235, 120);
	i[Y] = 0;
	while (i[Y] < 120)
	{
		i[X] = 0;
		while (i[X] < 235)
		{
			mlx_put_pixel(id->status_bar, i[X], i[Y], ft_pixel(0, 0, 0, 100));
			i[X]++;
		}
		i[Y]++;
	}
	mlx_put_string(id->mlx, "HOW TO USE", 65, 20);
	mlx_image_to_window(id->mlx, id->status_bar, 0, 0);
	mlx_put_string(id->mlx, "c = checkerboard", 30, 55);
	mlx_put_string(id->mlx, "b =  bump map", 45, 80);
	id->status_bar->instances->z = 1;
}
