/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usoontra <usoontra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 03:01:28 by usoontra          #+#    #+#             */
/*   Updated: 2025/05/04 23:20:24 by usoontra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

float	vector_dot(t_vector a, t_vector b)
{
	return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
}

t_vector	vector_add(t_vector a, t_vector b)
{
	t_vector	res;

	res.x = a.x + b.x;
	res.y = a.y + b.y;
	res.z = a.z + b.z;
	return (res);
}

t_vector	vector_sub(t_vector a, t_vector b)
{
	t_vector	res;

	res.x = a.x - b.x;
	res.y = a.y - b.y;
	res.z = a.z - b.z;
	return (res);
}

t_vector	vector_mul(t_vector a, float f)
{
	t_vector	res;

	res.x = a.x * f;
	res.y = a.y * f;
	res.z = a.z * f;
	return (res);
}

t_vector	vector_normalize(t_vector v)
{
	float	len;

	len = sqrtf(vector_dot(v, v));
	v.x = v.x / len;
	v.y = v.y / len;
	v.z = v.z / len;
	return (v);
}
