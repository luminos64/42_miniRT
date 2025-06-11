/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 21:14:01 by nchencha          #+#    #+#             */
/*   Updated: 2025/06/11 21:14:03 by nchencha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static bool	is_valid_number(char *str)
{
	int		i;
	bool	has_digit;
	bool	has_decimal;

	has_digit = false;
	has_decimal = false;
	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			has_digit = true;
		else if (str[i] == '.' && !has_decimal)
			has_decimal = true;
		else
			return (false);
		i++;
	}
	return (has_digit);
}

static bool	is_all_num(char **split_line)
{
	int	i;

	i = 1;
	while (split_line[i])
	{
		if (!is_valid_number(split_line[i]))
			return (false);
		i++;
	}
	return (true);
}

void	parser(t_data *id, char **av)
{
	int		fd;
	int		amb_cam[2];
	char	**split_line;
	char	*line;

	amb_cam[0] = 0;
	amb_cam[1] = 0;
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		exit (EXIT_FAILURE);
	line = get_next_valid_line(fd);
	while (line)
	{
		split_line = ft_split(line);
		free(line);
		if (!split_line || !is_all_num(split_line))
			ft_free_exit(split_line, id, fd, "Error");
		if (!check_and_assign(split_line, id, &amb_cam[0], &amb_cam[1]))
			ft_free_exit(split_line, id, fd, "Error");
		ft_doublefree(split_line);
		line = get_next_valid_line(fd);
	}
	if (amb_cam[0] == 0 || amb_cam[1] == 0)
		ft_free_exit(NULL, id, fd, "Error");
	close(fd);
}
