#include "miniRT.h"

t_color	trace_ray(t_data *id, t_camera *camera, t_vector c_direction)
{
	float		t;
	t_color		color;
	t_sphere	*shape;

	shape = id->shape;
	while (shape)
	{
		if (shape->type == SPHERE && sp_intersect(camera->origin, c_direction, shape, &t))
		{
			color = trace_sphere(id, c_direction, (t_sphere *)shape, t);
			return (color);
		}
		// else if (shape->type == PLANE && pl_intersect(camera->origin, c_direction, (t_plane *)shape, &t, id))
		// {
		// 	return ((t_color){255, 255, 255, 255});
		// }

		shape = shape->next;
	}
	return (id->bg);
}

void	render(void *param)
{
	t_data		*id;
	t_color		color;
	t_vector	c_direction;
	int			i[2];
	float		fov_scale;

	id = (t_data *)param;
	i[Y] = 0;
	while (i[Y] < WINY)
	{
		i[X] = 0;
		while (i[X] < WINX)
		{
			fov_scale = tan((id->camera->fov * 0.5) * (PI / 180));
			c_direction.x = (((float)(i[X] - (WINX / 2)) / WINX) * (2.0 - 1.0)) * (WINX / WINY) * fov_scale;
			c_direction.y = (((float)(i[Y] - (WINY / 2)) / WINY) * (2.0 - 1.0)) * fov_scale;
			c_direction = vec3_normalize(vec3_add(id->camera->direction,(t_vector){c_direction.x, c_direction.y, 0}));
			color = trace_ray(id, id->camera, c_direction);
			mlx_put_pixel(id->img, i[X], i[Y], ft_pixel(color.r, color.g, color.b, color.a));
			i[X]++;
		}
		i[Y]++;
	}
}

int main()
{
	t_data id;

	init_data(&id);
	parser(&id);
	display_info(&id);
	id.mlx = mlx_init(WINX, WINY, "miniRT", false); // true => can resize
	if (!id.mlx)
		return (EXIT_FAILURE);
	id.img = NULL;
	id.img = mlx_new_image(id.mlx, WINX, WINY);
	if (!id.img)
		return (EXIT_FAILURE);
	// render(&id);
	if (mlx_image_to_window(id.mlx, id.img, 0, 0) < 0)
		return (EXIT_FAILURE);	// render(&id);
	mlx_loop_hook(id.mlx, &render, &id);
	mlx_key_hook(id.mlx, &hook, &id);
	mlx_loop(id.mlx);
	mlx_terminate(id.mlx);
	free_success(&id);
	return (EXIT_SUCCESS);
}
