#include "miniRT.h"

bool	is_within_height_bounds(t_vec point, t_cylinder *cylin)
{
	t_vec	to_point;
	float	projection;

	to_point = vec3_sub(point, cylin->origin);
	projection = vec3_dot(to_point, cylin->normal);
	return (projection >= 0.0f && projection <= cylin->height);
}

static t_vec	calculate_hit_point(t_vec cam_origin, t_vec direction, float t)
{
	return (vec3_add(cam_origin, vec3_mul(direction, t)));
}

static bool	validate_intersection_point(float t, t_intersection_data *data)
{
	t_vec	hit_point;

	if (t <= 0.001f)
		return (false);
	hit_point = calculate_hit_point(data->cam_origin, data->direction, t);
	return (is_within_height_bounds(hit_point, data->cylin));
}

bool	find_closest_intersection(t_intersection_data *data, float *t)
{
	bool	t1_valid;
	bool	t2_valid;

	t1_valid = validate_intersection_point(data->t1, data);
	t2_valid = validate_intersection_point(data->t2, data);
	if (t1_valid && t2_valid)
	{
		if (data->t1 < data->t2)
			*t = data->t1;
		else
			*t = data->t2;
		return (true);
	}
	else if (t1_valid)
	{
		*t = data->t1;
		return (true);
	}
	else if (t2_valid)
	{
		*t = data->t2;
		return (true);
	}
	return (false);
}
