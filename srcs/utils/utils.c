/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 21:13:50 by nchencha          #+#    #+#             */
/*   Updated: 2025/06/11 21:13:52 by nchencha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	init_data(t_data *id)
{
	id->ambient = NULL;
	id->camera = NULL;
	id->light = NULL;
	id->plane = NULL;
	id->shape = NULL;
	id->cylynder = NULL;
	id->checker_board = false;
	id->bump_map = false;
	id->bg.r = 0;
	id->bg.g = 0;
	id->bg.b = 0;
	id->bg.a = 255;
	id->b_texture = NULL;
	return (true);
}

bool	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

bool	ft_isspace_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_isspace(line[i]) && line[i] != '\n')
			return (false);
		i++;
	}
	return (true);
}

bool	is_skippable_line(char *line)
{
	return (line[0] == '\n' || line[0] == '\0' || ft_isspace_line(line)
		|| line[0] == '#');
}

char	*get_next_valid_line(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line && is_skippable_line(line))
	{
		free(line);
		line = get_next_line(fd);
	}
	return (line);
}
/*
void	display_info(t_data *id)
{
	t_light		*curr_light = id->light;
	t_sphere	*curr_shape = id->shape;
	bool		sphere_found = false;
	bool		plane_found = false;
	bool		cylinder_found = false;

	if (!id)
		return;

	if (id->ambient)
	{
		printf("Ambient Info:\n");
		printf("Intense: %.2f\n", id->ambient->intens);
		printf("Color.x: %.2f\n", id->ambient->color.x);
		printf("Color.y: %.2f\n", id->ambient->color.y);
		printf("Color.z: %.2f\n", id->ambient->color.z);
	}
	else
		printf("\nNo Ambient found\n");

	if (id->camera)
	{
		printf("\nCamera Info:\n");
		printf("Origin.x: %.2f\n", id->camera->origin.x);
		printf("Origin.y: %.2f\n", id->camera->origin.y);
		printf("Origin.z: %.2f\n", id->camera->origin.z);
		printf("Direction.x: %.2f\n", id->camera->di.x);
		printf("Direction.y: %.2f\n", id->camera->di.y);
		printf("Direction.z: %.2f\n", id->camera->di.z);
		printf("FOV: %.2f\n", id->camera->fov);
	}
	else
		printf("\nNo Camera found\n");

	if (curr_light)
	{
		while (curr_light)
		{
			printf("\nLight Info:\n");
			printf("Origin.x: %.2f\n", curr_light->origin.x);
			printf("Origin.y: %.2f\n", curr_light->origin.y);
			printf("Origin.z: %.2f\n", curr_light->origin.z);
			printf("Bright: %.2f\n", curr_light->bright);
			printf("Color.x: %.2f\n", curr_light->color.x);
			printf("Color.y: %.2f\n", curr_light->color.y);
			printf("Color.z: %.2f\n", curr_light->color.z);
			curr_light = curr_light->next;
		}
	}
	else
		printf("\nNo Light found\n");
	if (curr_shape)
	{
		while (curr_shape)
		{
			if (curr_shape->type == SPHERE)
			{
				sphere_found = true;
				printf("\nSphere Info:\n");
				printf("Origin.x: %.2f\n", curr_shape->origin.x);
				printf("Origin.y: %.2f\n", curr_shape->origin.y);
				printf("Origin.z: %.2f\n", curr_shape->origin.z);
				printf("Radius: %.2f\n", curr_shape->radius);
				printf("Color.x: %.2f\n", curr_shape->color.x);
				printf("Color.y: %.2f\n", curr_shape->color.y);
				printf("Color.z: %.2f\n", curr_shape->color.z);
			}
			else if (curr_shape->type == PLANE)
			{
				plane_found = true;
				t_plane *plane = (t_plane *)curr_shape;
				printf("\nPlane Info:\n");
				printf("Origin.x: %.2f\n", plane->origin.x);
				printf("Origin.y: %.2f\n", plane->origin.y);
				printf("Origin.z: %.2f\n", plane->origin.z);
				printf("Direction.x: %.2f\n", plane->normal.x);
				printf("Direction.y: %.2f\n", plane->normal.y);
				printf("Direction.z: %.2f\n", plane->normal.z);
				printf("Color.x: %.2f\n", plane->color.x);
				printf("Color.y: %.2f\n", plane->color.y);
				printf("Color.z: %.2f\n", plane->color.z);
			}
			else if (curr_shape->type == CYLINDER)
			{
				cylinder_found = true;
				t_cylinder *cyl = (t_cylinder *)curr_shape;
				printf("\nCylinder Info:\n");
				printf("Origin.x: %.2f\n", cyl->origin.x);
				printf("Origin.y: %.2f\n", cyl->origin.y);
				printf("Origin.z: %.2f\n", cyl->origin.z);
				printf("Direction.x: %.2f\n", cyl->normal.x);
				printf("Direction.y: %.2f\n", cyl->normal.y);
				printf("Direction.z: %.2f\n", cyl->normal.z);
				printf("Diameter: %.2f\n", cyl->diameter);
				printf("Height: %.2f\n", cyl->height);
				printf("Color.x: %.2f\n", cyl->color.x);
				printf("Color.y: %.2f\n", cyl->color.y);
				printf("Color.z: %.2f\n", cyl->color.z);
			}
			curr_shape = curr_shape->next;
		}
	}
	if (!sphere_found)
		printf("\nNo Sphere found\n");
	if (!plane_found)
		printf("\nNo Plane found\n");
	if (!cylinder_found)
		printf("\nNo Cylinder found\n");
}
*/