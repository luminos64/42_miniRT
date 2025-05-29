
#include "miniRT.h"

void	hook(mlx_key_data_t key, void *param)
{
	t_data	*id;

	id = (t_data *)param;
	if (key.key == MLX_KEY_ESCAPE && key.action == MLX_PRESS)
	{
		ft_putstr_fd("ESC end miniRT\n", 2);
		mlx_terminate(id->mlx);
		free(id->camera);
		free(id->ambient);
		exit(0);
	}
	if (key.key == MLX_KEY_LEFT)
	{
		id->temp.x -= 0.1;
	}
	if (key.key == MLX_KEY_RIGHT)
	{
		id->temp.x += 0.1;
	}
	if (key.key == MLX_KEY_UP)
	{
		id->temp.y -= 0.1;
	}
	if (key.key == MLX_KEY_DOWN)
	{
		id->temp.y += 0.1;
	}
	if (key.key == MLX_KEY_Q)
	{
		id->temp.z += 0.1;
	}
	if (key.key == MLX_KEY_W)
	{
		id->temp.z -= 0.1;
	}
	if (key.key == MLX_KEY_A)
	{
		id->di.x += 0.01;
	}
	if (key.key == MLX_KEY_S)
	{
		id->di.x -= 0.01;
	}
}
