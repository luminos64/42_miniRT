#include "miniRT.h"

t_color	trace_ray(t_data *id, t_camera *camera, t_vector c_direction)
{
	float		t;
	t_color		color;
	t_sphere	*shape;

	shape = id->shape;
	while (shape)
	{
		if (shape->type == SPHERE && sp_intersect(camera->origin, c_direction, shape, &t))
		{
			color = trace_sphere(id, c_direction, (t_sphere *)shape, t);
			return (color);
		}
		// else if (shape->type == PLANE && pl_intersect(camera->origin, c_direction, (t_plane *)shape, &t, id))
		// {
		// 	return ((t_color){255, 255, 255, 255});
		// }

		shape = shape->next;
	}
	return (id->bg);
}

void	render(void *param)
{
	t_data		*id;
	t_color		color;
	t_vector	c_direction;
	int			i[2];
	float		fov_scale;

	id = (t_data *)param;
	i[Y] = 0;
	while (i[Y] < WINY)
	{
		i[X] = 0;
		while (i[X] < WINX)
		{
			fov_scale = tan((id->camera->fov * 0.5) * (PI / 180));
			c_direction.x = (((float)(i[X] - (WINX / 2)) / WINX) * (2.0 - 1.0)) * (WINX / WINY) * fov_scale;
			c_direction.y = (((float)(i[Y] - (WINY / 2)) / WINY) * (2.0 - 1.0)) * fov_scale;
			c_direction = vec3_normalize(vec3_add(id->camera->direction,(t_vector){c_direction.x, c_direction.y, 0}));
			color = trace_ray(id, id->camera, c_direction);
			mlx_put_pixel(id->img, i[X], i[Y], ft_pixel(color.r, color.g, color.b, color.a));
			i[X]++;
		}
		i[Y]++;
	}
}

int	get_thing(t_data *id)
{
	t_light 	*light1;
	t_light 	*light2;
	t_sphere	*shpere1;
	t_sphere	*shpere2;
	t_plane		*plane1;

	light1 = NULL;
	light1 = malloc(sizeof(t_light));
	if (!light1)
		return (EXIT_FAILURE);
	light1->origin.x = -50;
	light1->origin.y = 0;
	light1->origin.z = 20;
	light1->bright = 1;
	light1->color.x = 255 / 255.0f * light1->bright;
	light1->color.y = 255 / 255.0f * light1->bright;
	light1->color.z = 255 / 255.0f * light1->bright;
	light1->next = NULL;

	light2 = NULL;
	light2 = malloc(sizeof(t_light));
	if (!light2)
		return (EXIT_FAILURE);
	light2->origin.x = -1;
	light2->origin.y = -1;
	light2->origin.z = -1;
	light2->bright = 1;
	light2->color.x = 255 / 255.0f * light2->bright;
	light2->color.y = 255 / 255.0f * light2->bright;
	light2->color.z = 255 / 255.0f * light2->bright;
	light2->next = NULL;

	light1->next = light2;

	shpere1 = NULL;
	shpere1 = malloc(sizeof(t_sphere));
	if (!shpere1)
		return (EXIT_FAILURE);
	shpere1->type = 0;
	shpere1->origin.x = 0;
	shpere1->origin.y = 0;
	shpere1->origin.z = 20; // 300 r = 1 don't show
	shpere1->radius = 3;
	shpere1->color.x = 10 / 255.0f;
	shpere1->color.y = 0 / 255.0f;
	shpere1->color.z = 255 / 255.0f;
	shpere1->next = NULL;

	shpere2 = NULL;
	shpere2 = malloc(sizeof(t_sphere));
	if (!shpere2)
		return (EXIT_FAILURE);
	shpere2->type = 0;
	shpere2->origin.x = 10;
	shpere2->origin.y = 0;
	shpere2->origin.z = 20;
	shpere2->radius = 6;
	shpere2->color.x = 0 / 255.0f;
	shpere2->color.y = 130 / 255.0f;
	shpere2->color.z = 140 / 255.0f;
	shpere2->next = NULL;

	shpere1->next = shpere2;

	plane1 = NULL;
	plane1 = malloc(sizeof(t_plane));
	if (!plane1)
		return (EXIT_FAILURE);
	plane1->type = 1;
	plane1->origin.x = 0;
	plane1->origin.y = 0;
	plane1->origin.z = 20;
	plane1->direction.x = 0;
	plane1->direction.y = 0;
	plane1->direction.z = 0;
	plane1->color.x = 10 / 255.0f;
	plane1->color.y = 0 / 255.0f;
	plane1->color.z = 255 / 255.0f;
	plane1->next = NULL;

	shpere2->next = plane1;

	id->light = light1;
	id->shape = shpere1;
	return (EXIT_SUCCESS);
}

int	init(t_data *id)
{
	id->camera = malloc(sizeof(t_camera));
	if (!id->camera)
		return (EXIT_FAILURE);
	id->camera->origin.x = 0.0; // -50
	id->camera->origin.y = 0.0;
	id->camera->origin.z = 0.0; // 20
	id->camera->fov = 90; // max 90 - 110 // 70
	id->camera->direction.x = 0.0; // หมุนกลัอง x <- -, + ->
	id->camera->direction.y = 0.0; // "หมุนกลัอง y + \/, - /\"
	id->camera->direction.z = 1.0;

	id->ambient = malloc(sizeof(t_light_a));
	if (!id->ambient)
		return (EXIT_FAILURE);
	id->ambient->intens = 0.5;
	id->ambient->color.x = (255 / 255.0f) * id->ambient->intens;
	id->ambient->color.y = (255 / 255.0f) * id->ambient->intens;
	id->ambient->color.z = (255 / 255.0f) * id->ambient->intens;

	id->bg.r = 0;
	id->bg.g = 0;
	id->bg.b = 0;
	id->bg.a = 255;
	if (get_thing(id))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/*
int	main(void)
{
	t_data		id;

	init(&id);
	id.mlx = mlx_init(WINX, WINY, "miniRT", false); // true => can resize
	if (!id.mlx)
		return (EXIT_FAILURE);
	id.img = NULL;
	id.img = mlx_new_image(id.mlx, WINX, WINY);
	if (!id.img)
		return (EXIT_FAILURE);
	// render(&id);
	if (mlx_image_to_window(id.mlx, id.img, 0, 0) < 0)
		return (EXIT_FAILURE);	// render(&id);
	mlx_loop_hook(id.mlx, &render, &id);
	mlx_key_hook(id.mlx, &hook, &id);
	mlx_loop(id.mlx);
	mlx_terminate(id.mlx);
	free(id.camera);
	free(id.ambient);
}
*/

int main()
{
	t_data id;

	init_data(&id);
	parser(&id);
	//! Deleter this later
	display_info(&id);
	free_success(&id);
	return (EXIT_SUCCESS);
}


//TODO Comment this out when submit the work
void	display_info(t_data *id)
{
	t_light *curr_light = id->light;
	t_plane *curr_plane = id->plane;
	t_sphere *curr_sphere = id->shape;
	t_cylinder *curr_cylin = id->cylynder;

	if (!id)
		return ;

	if (id->ambient)
	{
		printf("Ambient Info: \n");
		printf("Intense: %.2f\n", id->ambient->intens);
		printf("Color.x: %.2f\n", id->ambient->color.x);
		printf("Color.y: %.2f\n", id->ambient->color.y);
		printf("Color.z: %.2f\n", id->ambient->color.z);
	}
	else
		printf("\nNo Ambient found\n");

	if (id->camera)
	{
		printf("\nCamera Info:\n");
		printf("Origin.x: %.2f\n", id->camera->origin.x);
		printf("Origin.y: %.2f\n", id->camera->origin.y);
		printf("Origin.z: %.2f\n", id->camera->origin.z);
		printf("Direction.x: %.2f\n", id->camera->direction.x);
		printf("Direction.y: %.2f\n", id->camera->direction.y);
		printf("Direction.z: %.2f\n", id->camera->direction.z);
		printf("FOV: %.2f\n", id->camera->fov);
	}
	else
		printf("\nNo Camera found\n");

	if (curr_light)
	{
		while (curr_light)
		{
			printf("\nLight Info:\n");
			printf("Origin.x: %.2f\n", curr_light->origin.x);
			printf("Origin.y: %.2f\n", curr_light->origin.y);
			printf("Origin.z: %.2f\n", curr_light->origin.z);
			printf("Bright: %.2f\n", curr_light->bright);
			printf("Color.x: %.2f\n", curr_light->color.x);
			printf("Color.y: %.2f\n", curr_light->color.y);
			printf("Color.z: %.2f\n", curr_light->color.z);
			curr_light = curr_light->next;
		}
	}
	else
		printf("\nNo Light found\n");


	if (curr_plane)	
	{
		while(curr_plane)
		{
			printf("\nPlane Info\n");
			printf("Origin.x: %.2f\n",curr_plane->origin.x);
			printf("Origin.x: %.2f\n",curr_plane->origin.y);
			printf("Origin.x: %.2f\n",curr_plane->origin.z);
			printf("Direction.x: %.2f\n", curr_plane->direction.x);
			printf("Direction.y: %.2f\n", curr_plane->direction.y);
			printf("Direction.z: %.2f\n", curr_plane->direction.z);
			printf("Color.x: %.2f\n", curr_plane->color.x);
			printf("Color.y: %.2f\n", curr_plane->color.y);
			printf("Color.z: %.2f\n", curr_plane->color.z);
			curr_plane = curr_plane->next;
		}
	}
	else
		printf ("\nNo Plane found");

	if (curr_sphere)
	{
		while (curr_sphere)
		{
			printf("\nSphere info:\n");
			printf("origin.x: %.2f\n",curr_sphere->origin.x);
			printf("origin.x: %.2f\n",curr_sphere->origin.y);
			printf("origin.x: %.2f\n",curr_sphere->origin.z);
			printf("radius: %.2f\n", curr_sphere->radius);
			printf("color.x: %.2f\n", curr_sphere->color.x);
			printf("color.y: %.2f\n", curr_sphere->color.y);
			printf("color.z: %.2f\n", curr_sphere->color.z);
			curr_sphere = curr_sphere->next;
		}
	}
	else
		printf("\nNo Sphere founded\n");

	if (curr_cylin)
	{
		while (curr_cylin)
		{
			printf("\nCylider Info\n");
			printf("Origin.x: %.2f\n",curr_cylin->origin.x);
			printf("Origin.y: %.2f\n",curr_cylin->origin.y);
			printf("Origin.z: %.2f\n",curr_cylin->origin.z);
			printf("Direction.x: %.2f\n", curr_cylin->direction.x);
			printf("Direction.y: %.2f\n", curr_cylin->direction.y);
			printf("Direction.z: %.2f\n", curr_cylin->direction.z);
			printf("Diameter: %.2f\n", curr_cylin->diameter);
			printf("Height: %.2f\n", curr_cylin->height);
			printf("Color.x: %.2f\n", curr_cylin->color.x);
			printf("Color.y: %.2f\n", curr_cylin->color.y);
			printf("Color.z: %.2f\n", curr_cylin->color.z);
			curr_cylin = curr_cylin->next;
		}
	}
	else
		printf("\nNo Cylinder found\n");
}
