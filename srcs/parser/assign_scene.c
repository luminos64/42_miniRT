#include "miniRT.h"

int	assign_ambient(t_data *id, char **split_line)
{
	if (!check_argument(split_line, 5))
		return (0);
	if (!check_color_values(split_line, 2))
		return (0);
	id->ambient = malloc(sizeof(t_light_a));
	if (!id->ambient)
		return (0);
	id->ambient->intens = ft_atof(split_line[1]);
	id->ambient->color.x = ft_atof(split_line[2]) / 255 * id->ambient->intens;
	id->ambient->color.y = ft_atof(split_line[3]) / 255 * id->ambient->intens;
	id->ambient->color.z = ft_atof(split_line[4]) / 255 * id->ambient->intens;
	if (!check_ambient(id))
		return (0);
	return (1);
}

int	assign_camera(t_data *id, char **split_line)
{
	if (!check_argument(split_line, 8))
		return (0);
	id->camera = malloc(sizeof(t_camera));
	if (!id->camera)
		return (0);
	id->camera->origin.x = ft_atof(split_line[1]);
	id->camera->origin.y = ft_atof(split_line[2]);
	id->camera->origin.z = ft_atof(split_line[3]);
	id->camera->di.x = ft_atof(split_line[4]);
	id->camera->di.y = ft_atof(split_line[5]);
	id->camera->di.z = ft_atof(split_line[6]);
	id->camera->fov = ft_atof(split_line[7]);
	if (!check_camera(id))
		return (0);
	return (1);
}

static void	addback_light_node(t_data *id, t_light *new_node)
{
	t_light	*current;

	if (!id || !new_node)
		return ;
	if (!id->light)
	{
		id->light = new_node;
		return ;
	}
	current = id->light;
	while (current->next)
		current = current->next;
	current->next = new_node;
}

int	assign_light(t_data *id, char **split_line)
{
	t_light	*light_node;

	if (!check_argument(split_line, 8))
		return (0);
	if (!check_color_values(split_line, 5))
		return (0);
	light_node = malloc(sizeof(t_light));
	if (!light_node)
		return (0);
	light_node->origin.x = ft_atof(split_line[1]);
	light_node->origin.y = ft_atof(split_line[2]);
	light_node->origin.z = ft_atof(split_line[3]);
	light_node->bright = ft_atof(split_line[4]);
	light_node->color.x = ft_atof(split_line[5]) / 255.0f * light_node->bright;
	light_node->color.y = ft_atof(split_line[6]) / 255.0f * light_node->bright;
	light_node->color.z = ft_atof(split_line[7]) / 255.0f * light_node->bright;
	light_node->next = NULL;
	if (!check_light_node(light_node))
	{
		free(light_node);
		return (0);
	}
	addback_light_node(id, light_node);
	return (1);
}
