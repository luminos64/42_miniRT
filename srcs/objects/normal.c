#include "miniRT.h"

t_vec	cal_normal(t_sphere *shape, t_vec hit)
{
	t_vec		normal;
	t_plane		*plane;
	t_cylinder	*cylinder;

	plane = NULL;
	cylinder = NULL;
	normal = (t_vec){0.0f, 0.0f, 0.0f};
	if (shape && shape->type == SPHERE)
	{
		normal = vec3_normalize(vec3_sub(hit, shape->origin));
	}
	else if (shape && shape->type == PLANE)
	{
		plane = (t_plane *)shape;
		normal = vec3_normalize(plane->normal);
	}
	// else
	// {
	// 	cylinder = (t_cylinder *)shape;
		// normal = (t_vec){0.0f, 0.0f, 0.0f};
	// }
	(void)cylinder;
	return (normal);
}
