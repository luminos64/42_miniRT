/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 21:17:04 by nchencha          #+#    #+#             */
/*   Updated: 2025/06/11 21:17:06 by nchencha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_sphere	*find_s(t_sphere *shape, t_camera *cam, t_vec c_dir, float *close_t)
{
	bool		hit;
	float		t;
	t_sphere	*closest_shape;

	closest_shape = NULL;
	while (shape)
	{
		hit = false;
		if (shape->type == SPHERE)
			hit = sp_intersect(cam->origin, c_dir, (t_sphere *)shape, &t);
		else if (shape->type == PLANE)
			hit = pl_intersect(cam->origin, c_dir, (t_plane *)shape, &t);
		else if (shape->type == CYLINDER)
			hit = cylin_intersect(cam->origin, c_dir, (t_cylinder *)shape, &t);
		if (hit && t > 0 && t < *close_t)
		{
			*close_t = t;
			closest_shape = shape;
		}
		shape = shape->next;
	}
	return (closest_shape);
}

static t_color	trace_ray(t_data *id, t_camera *camera, t_vec c_direction)
{
	float		closest_t;
	t_color		color;
	t_sphere	*closest_shape;

	closest_t = __FLT_MAX__;
	color = id->bg;
	closest_shape = find_s(id->shape, camera, c_direction, &closest_t);
	if (closest_shape)
		color = trace(id, c_direction, closest_shape, closest_t);
	return (color);
}

static void	projection(t_data *id, int x, int y)
{
	t_color	col;
	t_vec	c_dir;
	float	fov;

	y = 0;
	while (y < WINY)
	{
		x = 0;
		while (x < WINX)
		{
			fov = tan((id->camera->fov * 0.5) * (PI / 180));
			c_dir.x = ((float)(x - (WINX / 2)) / WINX) * (2.0 - 1.0);
			c_dir.x = c_dir.x * (WINX / WINY) * fov;
			c_dir.y = (((float)(y - (WINY / 2)) / WINY) * (2.0 - 1.0)) * fov;
			c_dir = vec3_add(id->camera->di, (t_vec){c_dir.x, c_dir.y, 0.0f});
			c_dir = vec3_normalize(c_dir);
			col = trace_ray(id, id->camera, c_dir);
			mlx_put_pixel(id->img, x, y, ft_pixel(col.r, col.g, col.b, col.a));
			x++;
		}
		y++;
	}
}

void	render(void *param)
{
	t_data		*id;
	int			i[2];

	id = (t_data *)param;
	if (id->img)
	{
		mlx_delete_image(id->mlx, id->img);
		id->img = NULL;
	}
	id->img = mlx_new_image(id->mlx, WINX, WINY);
	if (!id->img)
		return ;
	projection(id, i[X], i[Y]);
	if (mlx_image_to_window(id->mlx, id->img, 0, 0) < 0)
		return ;
	id->img->instances->z = 0;
}

int	main(int ac, char **av)
{
	t_data	id;

	if (ac != 2 || ft_strncmp(".rt", &av[1][ft_strlen(av[1]) - 3], 3))
		return (EXIT_FAILURE);
	id.b_texture = NULL;
	id.img = NULL;
	id.status_bar = NULL;
	id.mlx = NULL;
	if (!init_data(&id))
		return (EXIT_FAILURE);
	parser(&id, av);
	id.b_texture = mlx_load_png("./texture/brick.png");
	id.mlx = mlx_init(WINX, WINY, "miniRT", false);
	if (!id.mlx)
		return (EXIT_FAILURE);
	mlx_loop_hook(id.mlx, &render, &id);
	mlx_key_hook(id.mlx, &hook, &id);
	status_bar(&id);
	mlx_loop(id.mlx);
	mlx_delete_texture(id.b_texture);
	mlx_delete_image(id.mlx, id.img);
	mlx_delete_image(id.mlx, id.status_bar);
	mlx_terminate(id.mlx);
	free_success(&id);
	return (EXIT_SUCCESS);
}
