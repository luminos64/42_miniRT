
#include "miniRT.h"

float	vec3_dot(t_vector a, t_vector b)
{
	return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
}

t_vector	vec3_add(t_vector a, t_vector b)
{
	t_vector	res;

	res.x = a.x + b.x;
	res.y = a.y + b.y;
	res.z = a.z + b.z;
	return (res);
}

t_vector	vec3_sub(t_vector a, t_vector b)
{
	t_vector	res;

	res.x = a.x - b.x;
	res.y = a.y - b.y;
	res.z = a.z - b.z;
	return (res);
}

t_vector	vec3_mul(t_vector a, float f)
{
	t_vector	res;

	res.x = a.x * f;
	res.y = a.y * f;
	res.z = a.z * f;
	return (res);
}

t_vector	vec3_normalize(t_vector v)
{
	float	len;

	len = sqrtf(vec3_dot(v, v));
	v.x = v.x / len;
	v.y = v.y / len;
	v.z = v.z / len;
	return (v);
}
