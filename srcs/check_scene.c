#include "miniRT.h"

bool	check_argument(char **split_line, int limit)
{
	int	count;

	count = 0;
	if (!split_line)
		return (false);
	while (split_line[count])
		count++;
	if (count > limit)
		return (false);
	return (true);
}

bool	check_color(t_vector *color)
{
	if (color->x < 0 || color->y < 0 || color->z < 0)
		return (false);
	if (color->x > 256 || color->y > 256 || color->z > 256)
		return (false);
	return (true);
}

//Direction is Normalized in this code
bool	check_direction(t_vector *direction)
{
	if (direction->x < -1 || direction->y < -1 || direction->z < -1)
		return (false);
	if (direction->x > 1 || direction->y > 1 || direction->z > 1)
		return (false);
	return (true);
}

bool	check_ambient(t_data *id)
{
	if (!id || !id->ambient)
		return (false);
	if (id->ambient->intens < 0 || id->ambient->intens > 1)
		return (false);
	if (!check_color(&id->ambient->color))
		return (false);
	return (true);
}

bool	check_camera(t_data *id)
{
	if (!id || !id->camera)
		return (false);
	if (!check_direction(&id->camera->direction))
		return (false);
	if (id->camera->fov < 0 || id->camera->fov > 180)
		return (false);
	return (true);
}
