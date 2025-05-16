#include "miniRT.h"

void	init_data(t_data *id)
{
	id->ambient = NULL;
	id->camera = NULL;
	id->light = NULL;
	id->plane = NULL;
	id->shape = NULL;
	id->cylynder = NULL;
	id->bg.r = 0;
	id->bg.g = 0;
	id->bg.b = 0;
	id->bg.a = 255;
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
	return (line[0] == '\n' || line[0] == '\0' || ft_isspace_line(line));
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

//TODO Comment this out when submit the work
void	display_info(t_data *id)
{
	t_light *curr_light = id->light;
	t_plane *curr_plane = id->plane;
	t_sphere *curr_sphere = id->shape;
	t_cylinder *curr_cylin = id->cylynder;

	if (!id)
		return ;

	if (id->ambient)
	{
		printf("Ambient Info: \n");
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
		printf("Direction.x: %.2f\n", id->camera->direction.x);
		printf("Direction.y: %.2f\n", id->camera->direction.y);
		printf("Direction.z: %.2f\n", id->camera->direction.z);
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


	if (curr_plane)	
	{
		while(curr_plane)
		{
			printf("\nPlane Info\n");
			printf("Origin.x: %.2f\n",curr_plane->origin.x);
			printf("Origin.x: %.2f\n",curr_plane->origin.y);
			printf("Origin.x: %.2f\n",curr_plane->origin.z);
			printf("Direction.x: %.2f\n", curr_plane->direction.x);
			printf("Direction.y: %.2f\n", curr_plane->direction.y);
			printf("Direction.z: %.2f\n", curr_plane->direction.z);
			printf("Color.x: %.2f\n", curr_plane->color.x);
			printf("Color.y: %.2f\n", curr_plane->color.y);
			printf("Color.z: %.2f\n", curr_plane->color.z);
			curr_plane = curr_plane->next;
		}
	}
	else
		printf ("\nNo Plane found");

	if (curr_sphere)
	{
		while (curr_sphere)
		{
			printf("\nSphere info:\n");
			printf("origin.x: %.2f\n",curr_sphere->origin.x);
			printf("origin.x: %.2f\n",curr_sphere->origin.y);
			printf("origin.x: %.2f\n",curr_sphere->origin.z);
			printf("radius: %.2f\n", curr_sphere->radius);
			printf("color.x: %.2f\n", curr_sphere->color.x);
			printf("color.y: %.2f\n", curr_sphere->color.y);
			printf("color.z: %.2f\n", curr_sphere->color.z);
			curr_sphere = curr_sphere->next;
		}
	}
	else
		printf("\nNo Sphere founded\n");

	if (curr_cylin)
	{
		while (curr_cylin)
		{
			printf("\nCylider Info\n");
			printf("Origin.x: %.2f\n",curr_cylin->origin.x);
			printf("Origin.y: %.2f\n",curr_cylin->origin.y);
			printf("Origin.z: %.2f\n",curr_cylin->origin.z);
			printf("Direction.x: %.2f\n", curr_cylin->direction.x);
			printf("Direction.y: %.2f\n", curr_cylin->direction.y);
			printf("Direction.z: %.2f\n", curr_cylin->direction.z);
			printf("Diameter: %.2f\n", curr_cylin->diameter);
			printf("Height: %.2f\n", curr_cylin->height);
			printf("Color.x: %.2f\n", curr_cylin->color.x);
			printf("Color.y: %.2f\n", curr_cylin->color.y);
			printf("Color.z: %.2f\n", curr_cylin->color.z);
			curr_cylin = curr_cylin->next;
		}
	}
	else
		printf("\nNo Cylinder found\n");
}
