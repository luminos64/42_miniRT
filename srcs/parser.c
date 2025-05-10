#include "miniRT.h"

static bool check_and_assign(char **split_line, t_data *id)
{
	//TODO Do we really need to check for character error? 
	if (ft_isequal(split_line[0], "A"))
		return (assign_ambient(id, split_line));
	else if (ft_isequal(split_line[0], "C"))
		return (assign_camera(id, split_line));
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
	char	*line;
	int		fd;
	char	**split_line;

	fd = open("./srcs/data.rt", O_RDONLY);
	if (fd < 0)
		exit (EXIT_FAILURE);
	while ((line = get_next_line(fd)))
	{
		split_line = ft_split(line);
		free(line);
		if (!check_and_assign(split_line, id))
			ft_free_exit(split_line, "Error");
		ft_doublefree(split_line);
	}
	close(fd);
}

