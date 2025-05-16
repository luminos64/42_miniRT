#include "miniRT.h"

void	addback_plane_node(t_data *id, t_plane *new_node)
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

void	addback_sphere_node(t_data *id, t_sphere *new_node)
{
	t_sphere	*current;

	if (!id || !new_node)
		return ;
	new_node->next = NULL;
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

void	addback_cylin_node(t_data *id, t_cylinder *new_node)
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
