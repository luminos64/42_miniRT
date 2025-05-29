#include "miniRT.h"

bool	in_shadow(t_data *id, t_hit point, t_light *light, float *t)
{
	bool		hit;
	float		max_distance;
	t_vec		direction;
	t_vec		shadow_p;
	t_sphere	*shape;

	// Offset จุดเริ่มต้นเล็กน้อยตาม normal เพื่อป้องกัน self-shadowing
	shadow_p = vec3_add(point.hit_p, vec3_mul(point.normal, 0.001f));
	// ทิศทางจากจุดชนไปยังแสง
	direction = vec3_sub(light->origin, shadow_p); // หาทิศทางจาก point1 ไป point2
	max_distance = vec3_length(direction);
	direction = vec3_normalize(direction);
	shape = id->shape;
	// ตรวจสอบชนวัตถุแค่ระหว่างจุดกับแสง
	while (shape)
	{
		if (shape->type == SPHERE)
			hit = sp_intersect(shadow_p, direction, (t_sphere *)shape, t);
		if (shape->type == PLANE)
			hit = pl_intersect(shadow_p, direction, (t_plane *)shape, t);
		if (hit && *t < max_distance && shape != point.hit_shape)
			return (true);
		shape = shape->next;
	}
	return (false);
}
