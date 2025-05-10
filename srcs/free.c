#include "miniRT.h"

void	ft_free_exit(char **split_line,char *err_msg)
{
	printf("%s\n", err_msg);
	ft_doublefree(split_line);
	exit (EXIT_FAILURE);
}

int	free_id_err(t_data *id)
{
	free(id->ambient);
	free(id->camera);
	free(id->light);
	return (0);
}