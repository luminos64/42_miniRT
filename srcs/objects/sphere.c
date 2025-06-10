#include "miniRT.h"

static bool	intersect_sphere(float t0, float t1, float *t)
{
	float	max_distance;

	max_distance = __FLT_MAX__;
	// เลือกค่า t ที่เป็นบวกและมากกว่าเล็กน้อย (หลีกเลี่ยง self-intersection)
	if (t0 > 0.001f)
	{
		*t = t0;
		if (*t < max_distance)
			return (true);
	}
	else if (t1 > 0.001f)
	{
		*t = t1;
		if (*t < max_distance)
			return (true);
	}
	return (false);
}

bool	sp_intersect(t_vec origin, t_vec direction, t_sphere *shape, float *t)
{
	t_vec	oc;
	t_vec	temp;
	float	t0;
	float	t1;
	float	discriminant;

	oc = vec3_sub(origin, shape->origin);
	temp.x = vec3_dot(direction, direction);
	temp.y = 2.0f * vec3_dot(oc, direction);
	temp.z = vec3_dot(oc, oc) - (shape->radius * shape->radius);
	discriminant = (temp.y * temp.y) - (4 * temp.x * temp.z);
	if (discriminant < 0)
		return (false);
	temp.z = sqrtf(discriminant);
	t0 = (-temp.y - temp.z) / (2.0f * temp.x);
	t1 = (-temp.y + temp.z) / (2.0f * temp.x);
	return (intersect_sphere(t0, t1, t));
}

void	sphere_uv(t_hit hit, float *u, float *v)
{
	float	theta;
	float	phi;

	// คำนวณมุม spherical coordinates
	// θ (theta) คือมุม polar angle วัดจากแกน y (แกนตั้ง) ลงมา
		// คำนวณมุม polar angle θ จากแกน y (ลบเพื่อให้มุมเริ่มจากขั้วบน sphere)
	// ϕ (phi) คือมุม azimuthal angle วัดรอบแกน y ในระนาบ xz
	// คำนวณมุม azimuthal ϕ รอบแกน y โดยใช้ตำแหน่ง x และ z (ลบ z เพื่อทิศทางที่ถูกต้อง)
	// บวก π เพื่อเปลี่ยนช่วงมุมจาก [−π,π] เป็น [0,2π]
	theta = acosf(-hit.normal.y);
	phi = atan2f(-hit.normal.z, hit.normal.x) + PI;

	// แปลงมุมเป็นพิกัด UV ในช่วง
	// u คือสัดส่วนของมุม ϕ ต่อวงกลมเต็ม 360 องศา (2π)
	// v คือสัดส่วนของมุม θ ต่อมุมตั้งแต่ 0 ถึง π (ขั้วบนถึงขั้วล่างของ sphere)
	*u = phi / (2.0f * PI);
	*v = theta / PI;
	clamp_uv(u, v);
}
