/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 21:14:44 by nchencha          #+#    #+#             */
/*   Updated: 2025/06/11 21:14:46 by nchencha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static t_vec	calculate_cylinder_normal(t_cylinder *cylinder, t_vec hit)
{
	t_vec	axis;
	t_vec	to_hit;
	float	projection;
	t_vec	closest_point_on_axis;
	t_vec	normal;

	axis = vec3_normalize(cylinder->normal);
	to_hit = vec3_sub(hit, cylinder->origin);
	projection = vec3_dot(to_hit, axis);
	closest_point_on_axis = vec3_add(cylinder->origin,
			vec3_mul(axis, projection));
	normal = vec3_normalize(vec3_sub(hit, closest_point_on_axis));
	return (normal);
}

t_vec	cal_normal(t_sphere *shape, t_vec hit)
{
	t_vec		normal;
	t_plane		*plane;
	t_cylinder	*cylinder;

	plane = NULL;
	cylinder = NULL;
	normal = (t_vec){0.0f, 0.0f, 0.0f};
	if (shape && shape->type == SPHERE)
		normal = vec3_normalize(vec3_sub(hit, shape->origin));
	else if (shape && shape->type == PLANE)
	{
		plane = (t_plane *)shape;
		normal = vec3_normalize(plane->normal);
	}
	else if (shape && shape->type == CYLINDER)
	{
		cylinder = (t_cylinder *)shape;
		normal = calculate_cylinder_normal(cylinder, hit);
	}
	return (normal);
}
