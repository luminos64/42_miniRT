#include "miniRT.h"

void	ft_free_exit(char **split_line, t_data *id, int fd, char *err_msg)
{
	printf("%s\n", err_msg);
	free_success(id);
	if (split_line)
		ft_doublefree(split_line);
	close(fd);
	exit (EXIT_FAILURE);
}

void	free_success(t_data *id)
{
	if (!id)
		return ;
	if (id->ambient)
		free(id->ambient);
	if (id->camera)
		free(id->camera);
	if (id->light)
		free_light(id->light);
	if (id->plane)
		free_plane(id->plane);
	if (id->shape)
		free_sphere(id->shape);
	if (id->cylynder)
		free_cylin(id->cylynder);
}

void	free_light(t_light *light_node)
{
	t_light	*curr;
	t_light	*next_node;

	if (!light_node)
		return ;
	curr = light_node;
	while (curr)
	{
		next_node = curr->next;
		free(curr);
		curr = next_node;
	}
}
