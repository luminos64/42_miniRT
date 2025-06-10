#include "miniRT.h"

t_color	trace_ray(t_data *id, t_camera *camera, t_vec c_direction)
{
	bool		hit;
	float		t;
	float		closest_t;
	t_color		color;
	t_sphere	*shape;
	t_sphere	*closest_shape;

	hit = 0;
	closest_t = __FLT_MAX__;
	closest_shape = NULL;
	color = id->bg;
	shape = id->shape;
	while (shape)
	{
		if (shape->type == SPHERE)
			hit = sp_intersect(camera->origin, c_direction, (t_sphere *)shape, &t);
		else if (shape->type == PLANE)
			hit = pl_intersect(camera->origin, c_direction, (t_plane *)shape, &t);
		else if (shape->type == CYLINDER)
			hit = cylin_intersect(camera->origin, c_direction, (t_cylinder *)shape, &t);
		if (hit && t > 0 && t < closest_t)
		{
			closest_t = t;
			closest_shape = shape;
		}
		shape = shape->next;
	}
	if (closest_shape)
		color = trace(id, c_direction, closest_shape, closest_t);
	return (color);
}

/**_________________________________________________________
 *                                                         *
 *                           Y-axis                        *
 *        |------------------------------------------|     *
 *        |                   [-]                    |     *
 *        |                    |                     |     *
 *        |                    |                     |     *
 *        |__________________________________________|_____*__
 *        |                    |                     |     * |
 * X-axit |[-] . . . . . . . .[0]. . . . . . . . .[+]|     * |
 *        |                    |                     |     * |==> plane
 *        |                    |                     |     * |
 *        |                   [+]                    |     * |
 *        |------------------------------------------|_____*_|
 *                                                         *
 * ________________________________________________________*
 */

/**________________________________________________
 *                                                 *
 *                  Y-axis                         *
 *                                                 *
 *                   [-]                           *
 *                    |                            *
 *           c.len    |                            *
 *    CAM +-----------|------------> Z-axis [+]    *
 *  (Thera = FOV)     |                            *
 *                    |                            *
 *                   [+]                           *
 *                       [-]<-- Z-axis --->[+]     *
 *                                                 *
 *    1.0f / C.len = cotangent( Fov / 2 )          *
 * ________________________________________________*
 */

/**_______________________________________
 *                                       *
 *    CAM [.]      [-]                   *
 *  cam direction   .  plane             *
 *          \       .    |               *
 *           \      .    |               *
 *            \     .    |               *
 *             \    .    |               *
 *       _______\__obj___|___  plane     *
 *                  .                    *
 *                 [0]                   *
 *  [-]<-------- Z-axis -------->[+]     *
 *                  .                    *
 *                 [+]                   *
 *               Y-axis                  *
 * ______________________________________*
 */

void	render(void *param)
{
	t_data		*id;
	t_color		color;
	t_vec	c_direction;
	int			i[2];
	float		fov_scale;

	id = (t_data *)param;
	id->camera->origin.x += id->temp.x;
	id->camera->origin.y += id->temp.y;
	id->camera->origin.z += id->temp.z;
	id->camera->direction.y += id->di.x;
	// printf("o x %f	y %f	z %f		d y %f\n", id->camera->origin.x, id->camera->origin.y, id->camera->origin.z, id->camera->direction.y);
	i[Y] = 0;
	while (i[Y] < WINY)
	{
		i[X] = 0;
		while (i[X] < WINX)
		{
			fov_scale = tan((id->camera->fov * 0.5) * (PI / 180));
			c_direction.x = (((float)(i[X] - (WINX / 2)) / WINX) * (2.0 - 1.0)) * (WINX / WINY) * fov_scale;
			c_direction.y = (((float)(i[Y] - (WINY / 2)) / WINY) * (2.0 - 1.0)) * fov_scale;
			c_direction = vec3_normalize(vec3_add(id->camera->direction,(t_vec){c_direction.x, c_direction.y, 0}));
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
		return (EXIT_FAILURE);
	mlx_loop_hook(id.mlx, &render, &id);
	mlx_key_hook(id.mlx, &hook, &id);
	mlx_loop(id.mlx);
	mlx_terminate(id.mlx);
	free_success(&id);
	return (EXIT_SUCCESS);
}
