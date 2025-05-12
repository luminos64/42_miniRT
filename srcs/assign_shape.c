#include "miniRT.h"

static	void addback_plane_node(t_data *id, t_plane *new_node)
{
	t_plane	*current;

	if (!id || !new_node)
		return ;
	if (!id->plane)
	{
		id->plane = new_node;
		return ;
	}
	current = id->plane;
	while (current->next)
		current = current->next;
	current->next = new_node;
}

int			assign_plane(t_data *id, char **split_line)
{
	t_plane	*plane_node;

	if (!check_argument(split_line, 10))
		return (0);
	// id->plane = NULL;
	plane_node = malloc(sizeof(t_plane));
	if (!plane_node)
		return (0);
	plane_node->origin.x = ft_atof(split_line[1]);
	plane_node->origin.y = ft_atof(split_line[2]);
	plane_node->origin.z = ft_atof(split_line[3]);
	plane_node->direction.x = ft_atof(split_line[4]);
	plane_node->direction.y = ft_atof(split_line[5]);
	plane_node->direction.z = ft_atof(split_line[6]);
	plane_node->color.x = ft_atof(split_line[7]);
	plane_node->color.y = ft_atof(split_line[8]);
	plane_node->color.z = ft_atof(split_line[9]);
	plane_node->next = NULL;
	//!TODO Create check function 
	if (!check_plane_node(plane_node))
	{
		free(plane_node);
		return (0);
	}
	addback_plane_node(id, plane_node);
	//!Delete this
	// printf("\nPlane Info\n");
	// printf("Origin.x: %.2f\n",plane_node->origin.x);
	// printf("Origin.x: %.2f\n",plane_node->origin.y);
	// printf("Origin.x: %.2f\n",plane_node->origin.z);
	// printf("Direction.x: %.2f\n", plane_node->direction.x);
	// printf("Direction.y: %.2f\n", plane_node->direction.y);
	// printf("Direction.z: %.2f\n", plane_node->direction.z);
	// printf("Color.x: %.2f\n", plane_node->color.x);
	// printf("Color.y: %.2f\n", plane_node->color.y);
	// printf("Color.z: %.2f\n", plane_node->color.z);
	return (1);
}

static void addback_sphere_node(t_data *id, t_sphere *new_node)
{
	t_sphere	*current;

	if (!id || !new_node)
		return ;
	if (!id->shape)
	{
		id->shape = new_node;
		return ;
	}
	current = id->shape;
	while (current->next)
		current = current->next;
	current->next = new_node;
}

int			assign_sphere(t_data *id, char **split_line)
{
	t_sphere *sphere_node;

	if (!check_argument(split_line, 8))
		return (0);
	// id->shape = NULL;
	sphere_node = malloc(sizeof(t_sphere));
	if (!sphere_node)
		return (0);
	sphere_node->origin.x = ft_atof(split_line[1]);
	sphere_node->origin.y = ft_atof(split_line[2]);
	sphere_node->origin.z = ft_atof(split_line[3]);
	sphere_node->radius = ft_atof(split_line[4]);
	sphere_node->color.x = ft_atof(split_line[5]);
	sphere_node->color.y = ft_atof(split_line[6]);
	sphere_node->color.z = ft_atof(split_line[7]);
	sphere_node->next = NULL;
	if (!check_sphere_node(sphere_node))
	{
		free(sphere_node);
		return (false);
	}
	addback_sphere_node(id, sphere_node);
	//! Delete this
	// printf("\nsphere info:\n");
	// printf("origin.x: %.2f\n",sphere_node->origin.x);
	// printf("origin.x: %.2f\n",sphere_node->origin.y);
	// printf("origin.x: %.2f\n",sphere_node->origin.z);
	// printf("radius: %.2f\n", sphere_node->radius);
	// printf("color.x: %.2f\n", sphere_node->color.x);
	// printf("color.y: %.2f\n", sphere_node->color.y);
	// printf("color.z: %.2f\n", sphere_node->color.z);
	return (1);
}

static void addback_cylin_node(t_data *id, t_cylinder *new_node)
{
	t_cylinder	*current;

	if (!id || !new_node)
		return ;
	if (!id->cylynder)
	{
		id->cylynder = new_node;
		return ;
	}
	current = id->cylynder;
	while (current->next)
		current = current->next;
	current->next = new_node;
}

int			assign_cylinder(t_data *id, char **split_line)
{
	t_cylinder	*cylin_node;

	if (!check_argument(split_line, 12))
		return (0);
	// id->cylynder = NULL;
	cylin_node = malloc(sizeof(t_cylinder));;
	if (!cylin_node)
		return (0);
	cylin_node->origin.x = ft_atof(split_line[1]);
	cylin_node->origin.z = ft_atof(split_line[2]);
	cylin_node->origin.x = ft_atof(split_line[3]);
	cylin_node->direction.x = ft_atof(split_line[4]);
	cylin_node->direction.y = ft_atof(split_line[5]);
	cylin_node->direction.z = ft_atof(split_line[6]);
	cylin_node->diameter = ft_atof(split_line[7]);
	cylin_node->height = ft_atof(split_line[8]);
	cylin_node->color.x = ft_atof(split_line[9]);
	cylin_node->color.y = ft_atof(split_line[10]);
	cylin_node->color.z = ft_atof(split_line[11]);
	cylin_node->next = NULL;

	//TODO Create check function 
	if (!check_cylinder_node(cylin_node))
	{
		free(cylin_node);
		return (0);
	}
	addback_cylin_node(id, cylin_node);
	//! Delete this
	// printf("\nCylyder Info\n");
	// printf("Origin.x: %.2f\n",cylin_node->origin.x);
	// printf("Origin.y: %.2f\n",cylin_node->origin.y);
	// printf("Origin.z: %.2f\n",cylin_node->origin.z);
	// printf("Direction.x: %.2f\n", cylin_node->direction.x);
	// printf("Direction.y: %.2f\n", cylin_node->direction.y);
	// printf("Direction.z: %.2f\n", cylin_node->direction.z);
	// printf("Diameter: %.2f\n", cylin_node->diameter);
	// printf("Height: %.2f\n", cylin_node->diameter);
	// printf("Color.x: %.2f\n", cylin_node->color.x);
	// printf("Coloy.y: %.2f\n", cylin_node->color.y);
	// printf("Coloy.z: %.2f\n", cylin_node->color.z);
	return (1);
}