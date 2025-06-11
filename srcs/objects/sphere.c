#include "miniRT.h"

static bool	intersect_sphere(float t0, float t1, float *t)
{
	float	max_distance;

	max_distance = __FLT_MAX__;
	if (t0 > 0.001f)
	{
		*t = t0;
		if (*t < max_distance)
			return (true);
	}
	else if (t1 > 0.001f)
	{
		*t = t1;
		if (*t < max_distance)
			return (true);
	}
	return (false);
}

bool	sp_intersect(t_vec origin, t_vec direction, t_sphere *shape, float *t)
{
	t_vec	oc;
	t_vec	temp;
	float	t0;
	float	t1;
	float	discriminant;

	oc = vec3_sub(origin, shape->origin);
	temp.x = vec3_dot(direction, direction);
	temp.y = 2.0f * vec3_dot(oc, direction);
	temp.z = vec3_dot(oc, oc) - (shape->radius * shape->radius);
	discriminant = (temp.y * temp.y) - (4 * temp.x * temp.z);
	if (discriminant < 0)
		return (false);
	temp.z = sqrtf(discriminant);
	t0 = (-temp.y - temp.z) / (2.0f * temp.x);
	t1 = (-temp.y + temp.z) / (2.0f * temp.x);
	return (intersect_sphere(t0, t1, t));
}

void	sphere_uv(t_hit hit, float *u, float *v)
{
	float	theta;
	float	phi;

	theta = acosf(-hit.normal.y);
	phi = atan2f(-hit.normal.z, hit.normal.x) + PI;
	*u = phi / (2.0f * PI);
	*v = theta / PI;
	clamp_uv(u, v);
}
