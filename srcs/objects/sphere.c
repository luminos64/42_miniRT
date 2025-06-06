#include "miniRT.h"

static bool	intersect_sphere(float t0, float t1, float *t)
{
	float	max_distance;

	max_distance = __FLT_MAX__;
	// เลือกค่า t ที่เป็นบวกและมากกว่าเล็กน้อย (หลีกเลี่ยง self-intersection)
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
		return (0);
	temp.z = sqrtf(discriminant);
	t0 = (-temp.y - temp.z) / (2.0f * temp.x);
	t1 = (-temp.y + temp.z) / (2.0f * temp.x);
	return (intersect_sphere(t0, t1, t));
}
