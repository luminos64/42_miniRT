#include "miniRT.h"

static bool	check_and_assign(char **split_line, t_data *id, int *amb, int *cam)
{
	if (ft_isequal(split_line[0], "A"))
	{
		(*amb)++;
		if (*amb > 1)
			return (false);
		return (assign_ambient(id, split_line));
	}
	else if (ft_isequal(split_line[0], "C"))
	{
		(*cam)++;
		if (*cam > 1)
			return (false);
		return (assign_camera(id, split_line));
	}
	else if (ft_isequal(split_line[0], "L"))
		return (assign_light(id, split_line));
	else if (ft_isequal(split_line[0], "pl"))
		return (assign_plane(id, split_line));
	else if (ft_isequal(split_line[0], "sp"))
		return (assign_sphere(id, split_line));
	else if (ft_isequal(split_line[0], "cy"))
		return (assign_cylinder(id, split_line));
	else
		return (false);
	return (true);
}

void	parser(t_data *id)
{
	int		fd;
	int		amb_count;
	int		cam_count;
	char	**split_line;
	char	*line;

	amb_count = 0;
	cam_count = 0;
	fd = open("./srcs/data.rt", O_RDONLY);
	if (fd < 0)
		exit (EXIT_FAILURE);
	line = get_next_line(fd);
	while (line)
	{
		split_line = ft_split(line);
		free(line);
		if (!check_and_assign(split_line, id, &amb_count, &cam_count))
			ft_free_exit(split_line, "Error");
		ft_doublefree(split_line);
		line = get_next_line(fd);
	}
	close(fd);
}
