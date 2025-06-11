/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 21:15:05 by nchencha          #+#    #+#             */
/*   Updated: 2025/06/11 21:15:07 by nchencha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static bool	hit_shape(t_sphere *shape, t_vec shadow_p, t_vec di, t_hit point)
{
	bool	hit;
	float	max_distance;
	float	t;

	max_distance = vec3_length(di);
	di = vec3_normalize(di);
	while (shape)
	{
		hit = false;
		if (shape->type == SPHERE)
			hit = sp_intersect(shadow_p, di, (t_sphere *)shape, &t);
		else if (shape->type == PLANE)
			hit = pl_intersect(shadow_p, di, (t_plane *)shape, &t);
		else if (shape->type == CYLINDER)
			hit = cylin_intersect(shadow_p, di, (t_cylinder *)shape, &t);
		if (hit && t < max_distance && shape != point.hit_shape)
			return (true);
		shape = shape->next;
	}
	return (false);
}

bool	in_shadow(t_data *id, t_hit point, t_light *light)
{
	t_vec		direction;
	t_vec		shadow_p;

	shadow_p = vec3_add(point.hit_p, vec3_mul(point.normal, 0.001f));
	direction = vec3_sub(light->origin, shadow_p);
	if (hit_shape(id->shape, shadow_p, direction, point))
		return (true);
	return (false);
}
