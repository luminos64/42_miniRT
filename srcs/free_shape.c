#include "miniRT.h"

void	free_plane(t_plane *plane_node)
{
	t_plane	*curr;
	t_plane	*next_node;

	curr = plane_node;
	while (curr)
	{
		next_node = curr->next;
		free(curr);
		curr = next_node;
	}
}

void	free_sphere(t_sphere *sphere_node)
{
	t_sphere	*curr;
	t_sphere	*next_node;

	curr = sphere_node;
	while (curr)
	{
		next_node = curr->next;
		free(curr);
		curr = next_node;
	}
}

void	free_cylin(t_cylinder *cylin_node)
{
	t_cylinder	*curr;
	t_cylinder	*next_node;

	curr = cylin_node;
	while (curr)
	{
		next_node = curr->next;
		free(curr);
		curr = next_node;
	}
}
