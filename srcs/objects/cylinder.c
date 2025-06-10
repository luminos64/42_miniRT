#include "miniRT.h"

static void	calculate_intersection_points(t_intersection_coef *coef)
{
	float	sqrt_discriminant;

	sqrt_discriminant = sqrtf(coef->discriminant);
	*(coef->t1) = (-coef->b - sqrt_discriminant) / (2.0f * coef->a);
	*(coef->t2) = (-coef->b + sqrt_discriminant) / (2.0f * coef->a);
}

static bool	handle_parallel_ray(t_parallel_ray *ray, float *t)
{
	t_vec	hit_point;

	if (ray->c > 0)
		return (false);
	hit_point = vec3_add(ray->cam_origin, vec3_mul(ray->direction, 0.001f));
	if (is_within_height_bounds(hit_point, ray->cylin))
	{
		*t = 0.001f;
		return (true);
	}
	return (false);
}

static void	calculate_cylinder_coefficients(t_cylinder_coef *coef,
	t_coeef *coeef)
{
	t_vec	d_perp;
	t_vec	oc_perp;

	d_perp = vec3_sub(coef->direction,
			vec3_mul(coef->axis, vec3_dot(coef->direction, coef->axis)));
	oc_perp = vec3_sub(coef->oc,
			vec3_mul(coef->axis, vec3_dot(coef->oc, coef->axis)));
	coeef->a = vec3_dot(d_perp, d_perp);
	coeef->b = 2.0f * vec3_dot(oc_perp, d_perp);
	coeef->c = vec3_dot(oc_perp, oc_perp) - (coef->radius * coef->radius);
}

bool	cylin_intersect(t_vec cam_origin, t_vec direction,
	t_cylinder *cylin, float *t)
{
	t_cylinder_calc		calc;
	t_cylinder_coef		cyl_coef;
	t_parallel_ray		ray;
	t_intersection_coef	int_coef;
	t_intersection_data	data;

	calc.oc = vec3_sub(cam_origin, cylin->origin);
	cyl_coef = (t_cylinder_coef){direction, calc.oc,
		vec3_normalize(cylin->normal), cylin->diameter / 2.0f};
	calculate_cylinder_coefficients(&cyl_coef, &calc.coeef);
	calc.disc = calc.coeef.b * calc.coeef.b - 4 * calc.coeef.a * calc.coeef.c;
	if (calc.disc < 0)
		return (false);
	if (fabsf(calc.coeef.a) < 1e-6f)
	{
		ray = (t_parallel_ray){cam_origin, direction, cylin, calc.coeef.c};
		return (handle_parallel_ray(&ray, t));
	}
	int_coef = (t_intersection_coef){calc.disc, calc.coeef.a,
		calc.coeef.b, &calc.intersect[0], &calc.intersect[1]};
	calculate_intersection_points(&int_coef);
	data = (t_intersection_data){cam_origin, direction, cylin,
		calc.intersect[0], calc.intersect[1]};
	return (find_closest_intersection(&data, t));
}
