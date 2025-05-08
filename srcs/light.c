#include "miniRT.h"

static t_vector	specular(t_data *id, t_light *light, t_vector hit, t_vector color)
{
	t_vector	view_direction;
	t_vector	specular;
	float		spec;

	view_direction = vec3_normalize(vec3_sub(id->camera->origin, hit));
	view_direction = vec3_normalize(vec3_add(light->origin, view_direction));
	spec = fmaxf(0.0f, vec3_dot(hit, view_direction)); //คำนวณ dot product ระหว่าง normal กับ halfVector เพื่อวัดมุมของแสงสะท้อน
	spec = powf(spec, 40);

	// ค่า shininess		ลักษณะของแสงสะท้อน				ตัวอย่างพื้นผิว
	// ~1					แสงสะท้อนกว้าง กระจายมาก		ผิวหยาบ, ผิวด้าน
	// 16 - 64				แสงสะท้อนปานกลาง			พลาสติก, ผิวเรียบทั่วไป
	// 128 - 256+			แสงสะท้อนแคบและเข้มมาก		โลหะ, กระจก, ผิวมันวาวสูง

	specular = vec3_mul(light->color, spec);
	color = vec3_add(color, color_mul(light->color, specular));
	return (color);
}

static bool	in_shadow(t_data *id, t_vector hit, t_vector normal, t_light *light)
{
	float		max_distance;
	float		t;
	t_vector	direction;////////
	t_vector	shadow;
	t_sphere	*shape;

	shadow = vec3_add(hit, vec3_mul(normal, 0.001f));
	direction = vec3_sub(light->origin, shadow); // หาทิศทางจาก point1 ไป point2
	// ตรวจสอบชนวัตถุแค่ระหว่างจุดกับแสง
	max_distance = vec3_length(direction);
	direction = vec3_normalize(direction);
	shape = id->shape;
	while (shape)
	{
		if (shape->type == 0)
		{
			if (sp_intersect(shadow, direction, shape, &t))
			{
				if (t < max_distance)
					return (true);
			}
			// return (ray_intersect(light->origin, hit, shape, &max_distance));
		}
		// else if (shape->type == 1)
		// 	break ;
		shape = shape->next;
	}
	return (false);
}

t_color	light_cal(t_data *id, t_vector hit, t_vector normal, t_vector s_color)
{
	t_light		*temp;
	t_vector	light;
	t_vector	final_color_v;
	t_color		color;
	float		diffuse;

	final_color_v = color_mul(s_color, id->ambient->color);
	temp = id->light;
	while (temp)
	{
		light = vec3_normalize(vec3_sub(temp->origin, normal)); // diffuse light
		if (!in_shadow(id, hit, normal, temp))
		{
			diffuse = fmaxf(0.0f, vec3_dot(normal, light));
			light = vec3_mul(temp->color, diffuse);
			final_color_v = vec3_add(final_color_v, color_mul(s_color, light));
			final_color_v = specular(id, temp, normal, final_color_v);
		}
		temp = temp->next;
	}
	color.r = clamp(final_color_v.x, 0.0, 1.0) * 255;
	color.g = clamp(final_color_v.y, 0.0, 1.0) * 255;
	color.b = clamp(final_color_v.z, 0.0, 1.0) * 255;
	color.a = 255;
	return (color);
}
