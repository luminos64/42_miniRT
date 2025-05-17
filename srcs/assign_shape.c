#include "miniRT.h"

int	assign_plane(t_data *id, char **split_line)
{
	t_plane	*plane_node;

	if (!check_argument(split_line, 10))
		return (0);
	plane_node = malloc(sizeof(t_plane));
	if (!plane_node)
		return (0);
	plane_node->type = PLANE;
	plane_node->origin.x = ft_atof(split_line[1]);
	plane_node->origin.y = ft_atof(split_line[2]);
	plane_node->origin.z = ft_atof(split_line[3]);
	plane_node->direction.x = ft_atof(split_line[4]);
	plane_node->direction.y = ft_atof(split_line[5]);
	plane_node->direction.z = ft_atof(split_line[6]);
	plane_node->color.x = ft_atof(split_line[7]) / 255.0f;
	plane_node->color.y = ft_atof(split_line[8]) / 225.0f;
	plane_node->color.z = ft_atof(split_line[9]) / 255.0f;
	plane_node->next = NULL;
	if (!check_plane_node(plane_node))
	{
		free(plane_node);
		return (0);
	}
	addback_sphere_node(id, (t_sphere*)plane_node);
	return (1);
}

int	assign_sphere(t_data *id, char **split_line)
{
	t_sphere	*sphere_node;

	if (!check_argument(split_line, 8))
		return (0);
	sphere_node = malloc(sizeof(t_sphere));
	if (!sphere_node)
		return (0);
	sphere_node->type = SPHERE;
	sphere_node->origin.x = ft_atof(split_line[1]);
	sphere_node->origin.y = ft_atof(split_line[2]);
	sphere_node->origin.z = ft_atof(split_line[3]);
	sphere_node->radius = ft_atof(split_line[4]);
	sphere_node->color.x = ft_atof(split_line[5]) / 255.0f;
	sphere_node->color.y = ft_atof(split_line[6]) / 255.0f;
	sphere_node->color.z = ft_atof(split_line[7]) / 255.0f;
	sphere_node->next = NULL;
	if (!check_sphere_node(sphere_node))
	{
		free(sphere_node);
		return (false);
	}
	addback_sphere_node(id, sphere_node);
	return (1);
}

int	assign_cylinder(t_data *id, char **split_line)
{
	t_cylinder	*cylin_node;

	if (!check_argument(split_line, 12))
		return (0);
	cylin_node = malloc(sizeof(t_cylinder));
	cylin_node->type = CYLINDER;
	cylin_node->origin.x = ft_atof(split_line[1]);
	cylin_node->origin.y = ft_atof(split_line[2]);
	cylin_node->origin.z = ft_atof(split_line[3]);
	cylin_node->direction.x = ft_atof(split_line[4]);
	cylin_node->direction.y = ft_atof(split_line[5]);
	cylin_node->direction.z = ft_atof(split_line[6]);
	cylin_node->diameter = ft_atof(split_line[7]);
	cylin_node->height = ft_atof(split_line[8]);
	cylin_node->color.x = ft_atof(split_line[9]) / 255.0f;
	cylin_node->color.y = ft_atof(split_line[10]) / 255.0f;
	cylin_node->color.z = ft_atof(split_line[11]) / 255.0f;
	cylin_node->next = NULL;
	if (!check_cylinder_node(cylin_node))
	{
		free(cylin_node);
		return (0);
	}
	addback_sphere_node(id, (t_sphere*)cylin_node);
	return (1);
}
