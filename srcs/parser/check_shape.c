#include "miniRT.h"

bool	check_light_node(t_light *light_node)
{
	if (!light_node)
		return (false);
	if (light_node->bright < 0 || light_node->bright > 1)
		return (false);
	if (!check_color(&light_node->color))
		return (false);
	return (true);
}

bool	check_plane_node(t_plane *plane_node)
{
	if (!plane_node)
		return (false);
	if (!check_direction(&plane_node->normal))
		return (false);
	if (!check_color(&plane_node->color))
		return (false);
	return (true);
}

bool	check_sphere_node(t_sphere *sphere_node)
{
	if (!sphere_node)
		return (false);
	if (!check_color(&sphere_node->color))
		return (false);
	return (true);
}

bool	check_cylinder_node(t_cylinder *cylin_node)
{
	if (!cylin_node)
		return (false);
	if (!check_direction(&cylin_node->normal))
		return (false);
	if (!check_color(&cylin_node->color))
		return (false);
	return (true);
}
