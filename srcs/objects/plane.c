#include "miniRT.h"

bool	pl_intersect(t_vec ori, t_vec direction, t_plane *plane, float *t)
{
	t_vec	normal;
	t_vec	temp_vector;
	float	denominator;

	normal = vec3_normalize(plane->normal);
	denominator = vec3_dot(direction, normal);
	if (fabsf(denominator) < 1e-6f)
		return (false);
	temp_vector = vec3_sub(plane->origin, ori);
	denominator = vec3_dot(temp_vector, normal) / denominator;
	if (denominator < 0)
		return (false);
	*t = denominator;
	return (true);
}

void	plane_uv(t_hit hit, float *u, float *v)
{
	t_vec	arbitrary;
	t_vec	local;
	t_vec	u_axis;
	t_vec	v_axis;

	arbitrary.x = 0.0f;
	arbitrary.y = 1.0f;
	arbitrary.z = 0.0f;
	if (fabs(vec3_dot(hit.normal, arbitrary)) > 0.999f)
	{
		arbitrary.x = 1.0f;
		arbitrary.y = 0.0f;
		arbitrary.z = 0.0f;
	}
	u_axis = vec3_normalize(vec3_cross(hit.normal, arbitrary));
	v_axis = vec3_cross(hit.normal, u_axis);
	local = vec3_sub(hit.hit_p, hit.hit_shape->origin);
	*u = vec3_dot(local, u_axis) * 0.05f;
	*v = vec3_dot(local, v_axis) * 0.05f;
	clamp_uv(u, v);
}
