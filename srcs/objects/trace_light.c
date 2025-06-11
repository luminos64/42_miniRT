#include "miniRT.h"

static t_vec	specular(t_data *id, t_light *light, t_vec hit, t_vec col)
{
	t_vec	view_direction;
	t_vec	specular;
	float	spec;

	view_direction = vec3_normalize(vec3_sub(id->camera->origin, hit));
	view_direction = vec3_normalize(vec3_add(light->origin, view_direction));
	spec = fmaxf(0.0f, vec3_dot(hit, view_direction));
	spec = powf(spec, 40);
	specular = vec3_mul(light->color, spec);
	col = vec3_add(col, color_mul(light->color, specular));
	return (col);
}

static t_vec	diffuse_light(t_hit hit, t_light *light, t_vec color_vec3)
{
	t_vec	cal;
	float	diffuse;

	cal = vec3_normalize(vec3_sub(light->origin, hit.hit_p));
	if (hit.type == PLANE)
		cal = vec3_normalize(vec3_sub(hit.hit_p, light->origin));
	diffuse = fmaxf(0.0f, vec3_dot(hit.normal, cal));
	cal = vec3_mul(light->color, diffuse);
	cal = vec3_add(color_vec3, color_mul(hit.color, cal));
	return (cal);
}

static t_color	light_cal(t_data *id, t_hit hit)
{
	t_light	*light;
	t_vec	color_vec3;
	t_color	color;

	color_vec3 = color_mul(hit.color, id->ambient->color);
	light = id->light;
	while (light)
	{
		if (!in_shadow(id, hit, light))
		{
			color_vec3 = diffuse_light(hit, light, color_vec3);
			color_vec3 = specular(id, light, hit.normal, color_vec3);
		}
		light = light->next;
	}
	color.r = clamp(color_vec3.x, 0.0, 1.0) * 255;
	color.g = clamp(color_vec3.y, 0.0, 1.0) * 255;
	color.b = clamp(color_vec3.z, 0.0, 1.0) * 255;
	color.a = 255;
	return (color);
}

static void	cal_uv(t_sphere *shape, t_hit hit, float *u, float *v)
{
	if (shape->type == SPHERE)
		sphere_uv(hit, u, v);
	else if (shape->type == PLANE)
		plane_uv(hit, u, v);
	else
	{
		*u = 0;
		*v = 0;
	}
}

t_color	trace(t_data *id, t_vec c_direction, t_sphere *shape, float t)
{
	float		u;
	float		v;
	int			scale;
	t_hit		hit;
	t_color		color;

	scale = 8;
	hit.hit_shape = shape;
	hit.hit_p = vec3_add(id->camera->origin, vec3_mul(c_direction, t));
	hit.normal = cal_normal(shape, hit.hit_p);
	hit.type = shape->type;
	hit.color = shape->color;
	if (id->bump_map || id->checker_board)
		cal_uv(shape, hit, &u, &v);
	if (id->checker_board)
		hit.color = procedural_ckeckerboard(u, v, scale);
	if (id->bump_map)
		hit.normal = bump_mapping(id, u, v, hit);
	color = light_cal(id, hit);
	return (color);
}
