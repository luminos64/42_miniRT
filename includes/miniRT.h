/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usoontra <usoontra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 19:37:23 by usoontra          #+#    #+#             */
/*   Updated: 2025/05/05 00:45:02 by usoontra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "MLX42/MLX42.h"
# include "libft.h"
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>

# define WINX 1024
# define WINY 512

# define X 0
# define Y 1
# define Z 2

# define PI 3.14159

typedef struct s_vector
{
	float	x;
	float	y;
	float	z;
}	t_vector;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	a;
}	t_color;

typedef struct s_light_a
{
	float		intens; // [0.0, 1.0]
	t_vector	color; // r, g, b [0.0, 1.0]
}	t_light_a;

typedef struct s_camera
{
	float		fov; // view in degrees [70, 110]
	t_vector	origin;
	t_vector	direction; // x, y, z [-1 , 1]
}	t_camera;

typedef struct s_light
{
	struct s_light	*next;
	t_vector		origin;
	float			bright; // [0.0, 1.0]
	t_vector		color; // r, g, b [0.0, 1.0]
}	t_light;

typedef struct s_sphere
{
	struct s_sphere	*next;
	int				type;
	t_vector		origin;
	float			radius;
	t_vector		color; // r, g, b [0, 255]
}	t_sphere;

typedef struct s_plane
{
	t_sphere	*next;
	int			type;
	t_vector	origin;
	t_vector	direction; // x, y, z [-1 , 1]
	t_vector	color; // r, g, b [0, 255]
}	t_plane;

typedef struct s_cylinder
{
	t_sphere	*next;
	int			type;
	t_vector	origin;
	t_vector	direction; // x, y, z [-1 , 1]
	float		diameter;
	float		height;
	t_vector	color; // r, g, b [0, 255]
}	t_cylinder;

// type 0 = sphere
// type 1 = plane
// type 2 = cylinder

typedef struct s_data
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_light_a	*ambient;
	t_camera	*camera;
	t_color		bg;
	t_sphere	*shape;
	t_light		*light;
}	t_data;

float		vector_dot(t_vector a, t_vector b);
t_vector	vector_add(t_vector a, t_vector b);
t_vector	vector_sub(t_vector a, t_vector b);
t_vector	vector_mul(t_vector a, float f);
t_vector	vector_normalize(t_vector v);

t_vector	color_mul(t_vector color, t_vector mul);
float		vec3_length(t_vector v);
float		clamp(float value, float min, float max);

void		hook(mlx_key_data_t key, void *param);


#endif
