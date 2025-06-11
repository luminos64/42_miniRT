/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_shape.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 21:16:31 by nchencha          #+#    #+#             */
/*   Updated: 2025/06/11 21:16:33 by nchencha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	free_plane(t_plane *plane_node)
{
	t_plane	*curr;
	t_plane	*next_node;

	if (!plane_node)
		return ;
	curr = plane_node;
	while (curr)
	{
		next_node = curr->next;
		free(curr);
		curr = next_node;
	}
}

void	free_sphere(t_sphere *sphere_node)
{
	t_sphere	*curr;
	t_sphere	*next_node;

	if (!sphere_node)
		return ;
	curr = sphere_node;
	while (curr)
	{
		next_node = curr->next;
		free(curr);
		curr = next_node;
	}
}

void	free_cylin(t_cylinder *cylin_node)
{
	t_cylinder	*curr;
	t_cylinder	*next_node;

	if (!cylin_node)
		return ;
	curr = cylin_node;
	while (curr)
	{
		next_node = curr->next;
		free(curr);
		curr = next_node;
	}
}
