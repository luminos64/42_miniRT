#include "miniRT.h"

void	init_data(t_data *id)
{
	id->ambient = NULL;
	id->camera = NULL;
	id->light = NULL;
	id->plane = NULL;
	id->shape = NULL;
	id->cylynder = NULL;
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
