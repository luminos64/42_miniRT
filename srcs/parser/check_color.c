/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 21:16:05 by nchencha          #+#    #+#             */
/*   Updated: 2025/06/11 21:16:08 by nchencha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	has_decimal_point(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
			return (1);
		i++;
	}
	return (0);
}

int	check_color_values(char **split_line, int start_idx)
{
	float	colors[3];
	int		i;

	i = 0;
	while (i < 3)
	{
		if (has_decimal_point(split_line[start_idx + i]))
			return (0);
		colors[i] = ft_atof(split_line[start_idx + i]);
		if (colors[i] < 0 || colors[i] > 255)
			return (0);
		i++;
	}
	return (1);
}
