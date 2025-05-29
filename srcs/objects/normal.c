#include "miniRT.h"

t_vec	cal_normal(t_sphere *shape, t_vec hit)
{
	t_vec		normal;
	t_plane		*plane;
	t_cylinder	*cylinder;

	if (shape->type == SPHERE)
	{
		normal = vec3_normalize(vec3_sub(hit, shape->origin));
	}
	else
	{
		plane = (t_plane *)shape;
		normal = vec3_normalize(plane->normal);
	}
	// else (shape->type == CYLINDER)
	// {
	// 	cylinder = (t_cylinder *)shape;
	// 	// normal =
	// }
	(void)cylinder;
	return (normal);
}
