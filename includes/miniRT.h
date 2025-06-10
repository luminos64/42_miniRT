#ifndef MINIRT_H
# define MINIRT_H

# include "MLX42/MLX42.h"
# include "libft.h"
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdbool.h>

# define WINX 1024
# define WINY 512

# define X 0
# define Y 1
# define Z 2

# define PI 3.14159

# define SPHERE 0
# define PLANE 1
# define CYLINDER 2

typedef struct s_vec
{
	float	x;
	float	y;
	float	z;
}	t_vec;

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
	t_vec		color; // r, g, b [0.0, 1.0]
}	t_light_a;

typedef struct s_camera
{
	float		fov; // view in degrees [70, 110]
	t_vec		origin;
	t_vec		di; // x, y, z [-1 , 1]
}	t_camera;

typedef struct s_coeef
{
	float	a;
	float	b;
	float	c;
}	t_coeef;

typedef struct s_light
{
	struct s_light	*next;
	t_vec			origin;
	float			bright; // [0.0, 1.0]
	t_vec			color; // r, g, b [0.0, 1.0]
}	t_light;

typedef struct s_sphere
{
	void		*next;
	int			type;
	t_vec		color; // r, g, b [0, 255]
	t_vec		origin;
	float		radius;
}	t_sphere;

typedef struct s_plane
{
	void		*next;
	int			type;
	t_vec		color; // r, g, b [0, 255]
	t_vec		origin;
	t_vec		normal; // x, y, z [-1 , 1]
}	t_plane;

typedef struct s_cylinder
{
	void		*next;
	int			type;
	t_vec		color; // r, g, b [0, 255]
	t_vec		origin;
	t_vec		normal; // x, y, z [-1 , 1]
	float		diameter;
	float		height;
}	t_cylinder;

typedef struct s_intersection_data
{
	t_vec		cam_origin;
	t_vec		direction;
	t_cylinder	*cylin;
	float		t1;
	float		t2;
}	t_intersection_data;

typedef struct s_valid_intersections
{
	bool	t1_valid;
	bool	t2_valid;
	float	t1;
	float	t2;
}	t_valid_intersections;

typedef struct s_hit
{
	t_sphere	*hit_shape;
	t_vec		hit_p;
	t_vec		color;
	t_vec		normal;
	int			type;
}	t_hit;

typedef struct s_data
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	mlx_image_t		*status_bar;
	mlx_texture_t	*b_texture;
	t_light_a		*ambient;
	t_camera		*camera;
	t_color			bg;
	t_sphere		*shape;
	t_light			*light;
	t_plane			*plane;
	t_cylinder		*cylynder;
	bool			checker_board;
	bool			bump_map;
	t_vec			temp;
	t_vec			di;
}	t_data;

typedef struct s_intersection_coef
{
	float	discriminant;
	float	a;
	float	b;
	float	*t1;
	float	*t2;
}	t_intersection_coef;

typedef struct s_parallel_ray
{
	t_vec		cam_origin;
	t_vec		direction;
	t_cylinder	*cylin;
	float		c;
}	t_parallel_ray;

typedef struct s_cylinder_coef
{
	t_vec		direction;
	t_vec		oc;
	t_vec		axis;
	float		radius;
}	t_cylinder_coef;

typedef struct s_cylinder_calc
{
	t_coeef		coeef;
	t_vec		oc;
	float		disc;
	float		intersect[2];
}	t_cylinder_calc;

// vector_cal_01.c
float	vec3_dot(t_vec a, t_vec b);
t_vec	vec3_add(t_vec a, t_vec b);
t_vec	vec3_sub(t_vec a, t_vec b);
t_vec	vec3_mul(t_vec a, float f);
t_vec	vec3_normalize(t_vec v);

// vector_cal_02.c
t_vec	color_mul(t_vec color, t_vec mul);
t_vec	vec3_cross(t_vec a, t_vec b);
float	vec3_length(t_vec v);
float	clamp(float value, float min, float max);
int		ft_pixel(int r, int g, int b, int a);

// utils.c
bool	init_data(t_data *id);
bool	ft_isspace(char c);
bool	ft_isspace_line(char *line);
bool	is_skippable_line(char *line);
char	*get_next_valid_line(int fd);

// key_hook.c
void	hook(mlx_key_data_t key, void *param);
void	status_bar(t_data *id);

// sphere.c
bool	sp_intersect(t_vec origin, t_vec direction, t_sphere *shape, float *t);
void	sphere_uv(t_hit hit, float *u, float *v);

// plane.c
bool	pl_intersect(t_vec origin, t_vec direction, t_plane *plane, float *t);
void	plane_uv(t_hit hit, float *u, float *v);

// trace_light.c
t_color	trace(t_data *id, t_vec c_direction, t_sphere *shape, float t);

// normal
t_vec	cal_normal(t_sphere *shape, t_vec hit);

// cylinder
bool	cylin_intersect(t_vec cam_origin, t_vec nmlize_direct,
			t_cylinder *cylin, float *t);
bool	find_closest_intersection(t_intersection_data *data, float *t);
bool	is_within_height_bounds(t_vec point, t_cylinder *cylin);

// shadow_check
bool	in_shadow(t_data *id, t_hit point, t_light *light);

// texture
t_vec	procedural_ckeckerboard(float u, float v, int scale);
void	clamp_uv(float *u, float *v);
t_vec	bump_mapping(t_data *id, float u, float v, t_hit hit);

//parser
void	parser(t_data *data, char **av);

//checker scene
bool	check_argument(char **split_line, int limit);
bool	check_color(t_vec *color);
bool	check_direction(t_vec *direction);
bool	check_ambient(t_data *id);
bool	check_camera(t_data *id);

//checker shape
bool	check_light_node(t_light *light_node);
bool	check_plane_node(t_plane *plane_node);
bool	check_sphere_node(t_sphere *sphere_node);
bool	check_cylinder_node(t_cylinder *cylin_node);

//free
void	free_success(t_data *id);
void	ft_free_exit(char **split_line, t_data *data, int fd, char *err_msg);
void	free_light(t_light *light_node);

//free_shape
void	free_plane(t_plane *plane_node);
void	free_sphere(t_sphere *sphere_node);
void	free_cylin(t_cylinder *cylin_node);

//assign scene
int		assign_ambient(t_data *id, char **split_line);
int		assign_camera(t_data *id, char **split_line);
int		assign_light(t_data *id, char **split_line);

//assign shape
int		assign_plane(t_data *id, char **split_line);
int		assign_sphere(t_data *id, char **split_line);
int		assign_cylinder(t_data *id, char **split_line);

//addback shape
void	addback_plane_node(t_data *id, t_plane *new_node);
void	addback_sphere_node(t_data *id, t_sphere *new_node);
void	addback_cylin_node(t_data *id, t_cylinder *new_node);

//TODO comment this out later
void	display_info(t_data *id);

#endif
