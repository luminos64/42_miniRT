
#include "miniRT.h"

float	vec3_dot(t_vec a, t_vec b)
{
	return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
}

t_vec	vec3_add(t_vec a, t_vec b)
{
	t_vec	res;

	res.x = a.x + b.x;
	res.y = a.y + b.y;
	res.z = a.z + b.z;
	return (res);
}

t_vec	vec3_sub(t_vec a, t_vec b)
{
	t_vec	res;

	res.x = a.x - b.x;
	res.y = a.y - b.y;
	res.z = a.z - b.z;
	return (res);
}

t_vec	vec3_mul(t_vec a, float f)
{
	t_vec	res;

	res.x = a.x * f;
	res.y = a.y * f;
	res.z = a.z * f;
	return (res);
}

t_vec	vec3_normalize(t_vec v)
{
	float	len;

	len = sqrtf(vec3_dot(v, v));
	if (len > 1e-6) // ป้องกันการหารด้วย 0
	{
		v.x = v.x / len;
		v.y = v.y / len;
		v.z = v.z / len;
	}
	else
	{
		v.x = 0.0f;
		v.y = 0.0f;
		v.z = 0.0f;
	}
	return (v);
}
