/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usoontra <usoontra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 19:36:48 by usoontra          #+#    #+#             */
/*   Updated: 2025/05/06 01:07:01 by usoontra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	ft_pixel(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int	ray_intersect(t_vector origin, t_vector direction, t_sphere *shape, float *t)
{
	t_vector	oc;
	t_vector	temp;
	float		t0;
	float		t1;
	float		discriminant;

	oc = vector_sub(origin, shape->origin);
	temp.x = vector_dot(direction, direction);
	temp.y = 2.0f * vector_dot(oc, direction);
	temp.z = vector_dot(oc, oc) - (shape->radius * shape->radius);
	discriminant = (temp.y * temp.y) - (4 * temp.x * temp.z);
	if (discriminant < 0)
		return (0);
	temp.z = sqrtf(discriminant);
	t0 = (-temp.y - temp.z) / (2.0f * temp.x);
	t1 = (-temp.y + temp.z) / (2.0f * temp.x);
	// เลือกค่า t ที่เป็นบวกและมากกว่าเล็กน้อย (หลีกเลี่ยง self-intersection)
	if (t0 > 0.001f)
	{
		*t = t0;
		return (1);
	}
	if (t1 > 0.001f)
	{
		*t = t1;
		return (1);
	}
	return (0);
}

bool	in_shadow(t_data *id, t_vector hit, t_vector normal, t_light *light)
{
	float		max_distance;
	float		t;
	t_vector	direction;////////
	t_vector	shadow;
	t_sphere	*shape;

	shadow = vector_add(hit, vector_mul(normal, 0.001f));
	direction = vector_sub(light->origin, shadow); // หาทิศทางจาก point1 ไป point2
	// ตรวจสอบชนวัตถุแค่ระหว่างจุดกับแสง
	max_distance = vec3_length(direction);
	direction = vector_normalize(direction);
	shape = id->shape;
	while (shape)
	{
		if (shape->type == 0)
		{
			if (ray_intersect(shadow, direction, shape, &t))
			{
				if (t < max_distance)
					return (true);
			}
			// return (ray_intersect(light->origin, hit, shape, &max_distance));
		}
		// else if (shape->type == 1)
		// 	break ;
		shape = shape->next;
	}
	return (false);
}

t_vector	specular(t_data *id, t_light *light, t_vector hit, t_vector color)
{
	t_vector	view_direction;
	t_vector	specular;
	float		spec;

	view_direction = vector_normalize(vector_sub(id->camera->origin, hit));
	view_direction = vector_normalize(vector_add(light->origin, view_direction));
	spec = fmaxf(0.0f, vector_dot(hit, view_direction)); //คำนวณ dot product ระหว่าง normal กับ halfVector เพื่อวัดมุมของแสงสะท้อน
	spec = powf(spec, 40);

	// ค่า shininess		ลักษณะของแสงสะท้อน				ตัวอย่างพื้นผิว
	// ~1					แสงสะท้อนกว้าง กระจายมาก		ผิวหยาบ, ผิวด้าน
	// 16 - 64				แสงสะท้อนปานกลาง			พลาสติก, ผิวเรียบทั่วไป
	// 128 - 256+			แสงสะท้อนแคบและเข้มมาก		โลหะ, กระจก, ผิวมันวาวสูง

	specular = vector_mul(light->color, spec);
	color = vector_add(color, color_mul(light->color, specular));
	return (color);
}

t_color	light_cal(t_data *id, t_vector hit, t_vector normal, t_vector s_color)
{
	t_light		*temp;
	t_vector	light;
	t_vector	final_color_v;
	t_color		color;
	float		diffuse;

	final_color_v = color_mul(s_color, id->ambient->color);
	temp = id->light;
	while (temp)
	{
		light = vector_normalize(vector_sub(temp->origin, normal)); // diffuse light
		if (!in_shadow(id, hit, normal, temp))
		{
			diffuse = fmaxf(0.0f, vector_dot(normal, light));
			light = vector_mul(temp->color, diffuse);
			final_color_v = vector_add(final_color_v, color_mul(s_color, light));
			final_color_v = specular(id, temp, normal, final_color_v);
		}
		temp = temp->next;
	}
	color.r = clamp(final_color_v.x, 0.0, 1.0) * 255;
	color.g = clamp(final_color_v.y, 0.0, 1.0) * 255;
	color.b = clamp(final_color_v.z, 0.0, 1.0) * 255;
	color.a = 255;
	return (color);
}

t_color	trace_ray(t_data *id, t_camera *camera, t_vector direction)
{
	float		t;
	float		max;
	t_vector	hit;
	t_vector	normal;
	t_color		color;
	t_sphere	*sphere;

	max = __FLT_MAX__;
	sphere = id->shape;
	while (sphere)
	{
		if (ray_intersect(camera->origin, direction, sphere, &t))
		{
			if (t < max)
			{
				printf("t < max\n");
				max = t;
				hit = vector_add(camera->origin, vector_mul(direction, t));
				normal = vector_normalize(vector_sub(hit, sphere->origin));
				color = light_cal(id, hit, normal, sphere->color);
				return (color);
			}
		}
		sphere = sphere->next;
	}
	return (id->bg);
}

void	render(void *param)
{
	t_data		*id;
	t_color		col;
	t_vector	direction;
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
			direction.x = (((float)(i[X] - (WINX / 2)) / WINX) * (2.0 - 1.0)) * (WINX / WINY) * fov_scale;
			direction.y = (((float)(i[Y] - (WINY / 2)) / WINY) * (2.0 - 1.0)) * fov_scale;
			direction = vector_normalize(vector_add(id->camera->direction,(t_vector){direction.x, direction.y, 0}));
			col = trace_ray(id, id->camera, direction);
			mlx_put_pixel(id->img, i[X], i[Y], ft_pixel(col.r, col.g, col.b, col.a));
			i[X]++;
		}
		i[Y]++;
	}
}

int	get_thing(t_data *id)
{
	t_light 	*light1;
	t_light 	*light2;
	t_sphere	*shpere1;
	t_sphere	*shpere2;

	light1 = NULL;
	light1 = malloc(sizeof(t_light));
	if (!light1)
		return (EXIT_FAILURE);
	light1->origin.x = -50;
	light1->origin.y = 0;
	light1->origin.z = 20;
	light1->bright = 1;
	light1->color.x = 255 / 255.0f * light1->bright;
	light1->color.y = 255 / 255.0f * light1->bright;
	light1->color.z = 255 / 255.0f * light1->bright;
	light1->next = NULL;

	light2 = NULL;
	light2 = malloc(sizeof(t_light));
	if (!light2)
		return (EXIT_FAILURE);
	light2->origin.x = -1;
	light2->origin.y = -1;
	light2->origin.z = -1;
	light2->bright = 1;
	light2->color.x = 255 / 255.0f * light2->bright;
	light2->color.y = 255 / 255.0f * light2->bright;
	light2->color.z = 255 / 255.0f * light2->bright;
	light2->next = NULL;

	light1->next = light2;

	shpere1 = NULL;
	shpere1 = malloc(sizeof(t_sphere));
	if (!shpere1)
		return (EXIT_FAILURE);
	shpere1->type = 0;
	shpere1->origin.x = 0;
	shpere1->origin.y = 0;
	shpere1->origin.z = 20; // 300 r = 1 don't show
	shpere1->radius = 3;
	shpere1->color.x = 10 / 255.0f;
	shpere1->color.y = 0 / 255.0f;
	shpere1->color.z = 255 / 255.0f;
	shpere1->next = NULL;

	shpere2 = NULL;
	shpere2 = malloc(sizeof(t_sphere));
	if (!shpere2)
		return (EXIT_FAILURE);
	shpere2->type = 0;
	shpere2->origin.x = 10;
	shpere2->origin.y = 0;
	shpere2->origin.z = 20;
	shpere2->radius = 6;
	shpere2->color.x = 0 / 255.0f;
	shpere2->color.y = 130 / 255.0f;
	shpere2->color.z = 140 / 255.0f;
	shpere2->next = NULL;

	shpere1->next = shpere2;

	id->light = light1;
	id->shape = shpere1;
	return (EXIT_SUCCESS);
}

int	init(t_data *id)
{
	id->camera = malloc(sizeof(t_camera));
	if (!id->camera)
		return (EXIT_FAILURE);
	id->camera->origin.x = 0.0; // -50
	id->camera->origin.y = 0.0;
	id->camera->origin.z = 0.0; // 20
	id->camera->fov = 90; // max 90 - 110 // 70
	id->camera->direction.x = 0.0; // หมุนกลัอง x <- -, + ->
	id->camera->direction.y = 0.0; // "หมุนกลัอง y + \/, - /\"
	id->camera->direction.z = 1.0;

	id->ambient = malloc(sizeof(t_light_a));
	if (!id->ambient)
		return (EXIT_FAILURE);
	id->ambient->intens = 0.5;
	id->ambient->color.x = (255 / 255.0f) * id->ambient->intens;
	id->ambient->color.y = (255 / 255.0f) * id->ambient->intens;
	id->ambient->color.z = (255 / 255.0f) * id->ambient->intens;

	id->bg.r = 0;
	id->bg.g = 0;
	id->bg.b = 0;
	id->bg.a = 255;
	if (get_thing(id))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

// ft_memset(id.bg->pixels, 0, WINX * WINY * sizeof(int32_t));

int	main(void)
{
	t_data		id;

	init(&id);
	// printf("camera\norigin\n");
	// printf("x = %f	y = %f	z = %f\n", id.camera->origin.x, id.camera->origin.y, id.camera->origin.z);
	// printf("direction\n");
	// printf("x = %f	y = %f	z = %f\n", id.camera->direction.x, id.camera->direction.y, id.camera->direction.z);
	// printf("ambient	intens = %f\n", id.ambient->intens);
	// printf("r = %d	g = %d	b = %d	a = %d\n", id.ambient->color.r, id.ambient->color.g, id.ambient->color.b, id.ambient->color.a);

	id.mlx = mlx_init(WINX, WINY, "miniRT", false); // true => can resize
	if (!id.mlx)
		return (EXIT_FAILURE);
	id.img = NULL;
	id.img = mlx_new_image(id.mlx, WINX, WINY);
	if (!id.img)
		return (EXIT_FAILURE);
	render(&id);
	if (mlx_image_to_window(id.mlx, id.img, 0, 0) < 0)
		return (EXIT_FAILURE);	// render(&id);
	// mlx_loop_hook(id.mlx, &render, &id);
	mlx_key_hook(id.mlx, &hook, &id);
	mlx_loop(id.mlx);
	mlx_terminate(id.mlx);
	free(id.camera);
	free(id.ambient);
}
