#include "miniRT.h"

void	ft_free_exit(char **split_line, t_data *id, int fd, char *err_msg)
{
	printf("%s\n", err_msg);
	free_success(id);
	ft_doublefree(split_line);
	close(fd);
	exit (EXIT_FAILURE);
}

void	free_success(t_data *id)
{
	free(id->ambient);
	free(id->camera);
	free_light(id->light);
	free_plane(id->plane);
	free_sphere(id->shape);
	free_cylin(id->cylynder);
}

void	free_light(t_light *light_node)
{
	t_light	*curr;
	t_light	*next_node;

	curr = light_node;
	while (curr)
	{
		next_node = curr->next;
		free(curr);
		curr = next_node;
	}
}
