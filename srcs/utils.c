/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usoontra <usoontra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 20:45:28 by usoontra          #+#    #+#             */
/*   Updated: 2025/05/05 00:27:39 by usoontra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vector	color_mul(t_vector color, t_vector mul)
{
	color.x = color.x * mul.x;
	color.y = color.y * mul.y;
	color.z = color.z * mul.z;
	return (color);
}

float	vec3_length(t_vector v)
{
	return (sqrtf((v.x * v.x) + (v.y * v.y) + (v.z * v.z)));
}

float	clamp(float value, float min, float max)
{
	if (value < min)
		return (min);
	else if (value > max)
		return (max);
	return (value);
}
