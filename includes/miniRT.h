
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

# define SPHERE 0
# define PLANE 1
# define CYLINDER 2

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
	void		*next;
	int			type;
	t_vector	origin;
	float		radius;
	t_vector	color; // r, g, b [0, 255]
}	t_sphere;

typedef struct s_plane
{
	void		*next;
	int			type;
	t_vector	origin;
	t_vector	direction; // x, y, z [-1 , 1]
	t_vector	color; // r, g, b [0, 255]
}	t_plane;

typedef struct s_cylinder
{
	void		*next;
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
	t_vector	temp;
}	t_data;


// vector.c
float		vec3_dot(t_vector a, t_vector b);
t_vector	vec3_add(t_vector a, t_vector b);
t_vector	vec3_sub(t_vector a, t_vector b);
t_vector	vec3_mul(t_vector a, float f);
t_vector	vec3_normalize(t_vector v);

// utils.c
t_vector	color_mul(t_vector color, t_vector mul);
t_vector	vec3_cross(t_vector a, t_vector b);
float		vec3_length(t_vector v);
float		clamp(float value, float min, float max);
int			ft_pixel(int r, int g, int b, int a);

// key_hook.c
void		hook(mlx_key_data_t key, void *param);

// sphere.c
bool		sp_intersect(t_vector origin, t_vector direction, t_sphere *shape, float *t);
t_color		trace_sphere(t_data *id, t_vector c_direction, t_sphere *sphere, float t);

// plane.c
bool		pl_intersect(t_vector origin, t_vector direction, t_plane *plane, float *t, t_data *id);

// light.c
t_color		light_cal(t_data *id, t_vector hit, t_vector normal, t_vector s_color);


#endif
