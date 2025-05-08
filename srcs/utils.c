
#include "miniRT.h"

t_vector	color_mul(t_vector color, t_vector mul)
{
	color.x = color.x * mul.x;
	color.y = color.y * mul.y;
	color.z = color.z * mul.z;
	return (color);
}

t_vector	vec3_cross(t_vector a, t_vector b)
{
	t_vector	res;

	res.x = a.y * b.z - a.z * b.y;
	res.y = a.z * b.x - a.x * b.z;
	res.z = a.x * b.y - a.y * b.x;

	return (res);
}

float	vec3_length(t_vector v)
{
	return (sqrtf((v.x * v.x) + (v.y * v.y) + (v.z * v.z)));
}

float	clamp(float value, float min, float max)
{
	if (value < min)
		return (min);
	else if (value > max)
		return (max);
	return (value);
}

int	ft_pixel(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}
