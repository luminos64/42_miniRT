#include "miniRT.h"

bool	pl_intersect(t_vec ori, t_vec direction, t_plane *plane, float *t)
{
	t_vec	normal;
	t_vec	temp_vector;
	float	denominator;

	// Normalize direction vector ของระนาบ
	normal = vec3_normalize(plane->normal);
	// ถ้า denom ใกล้ 0 แสดงว่ารังสีขนานกับระนาบ ไม่มีจุดตัด
	denominator = vec3_dot(direction, normal);
	if (fabsf(denominator) < 1e-6f)
		return (false);
	// คำนวณเวกเตอร์จาก origin รังสีถึงจุดบนระนาบ
	temp_vector = vec3_sub(plane->origin, ori);

	// คำนวณ t ตามสูตร t = (C - O)·N / D·N
	// *t = vec3_dot(temp_vector, normal) / denominator;
	denominator = vec3_dot(temp_vector, normal) / denominator;

	// ถ้า t < 0 จุดตัดอยู่ด้านหลังจุดกำเนิดรังสี ไม่สนใจ
	if (denominator < 0)
		return (false);

	// เก็บค่า t ที่ตำแหน่งที่ชี้
	*t = denominator;
	return (true);
}

void	plane_uv(t_hit hit, float *u, float *v)
{
	t_vec	arbitrary;
	t_vec	local;
	t_vec	u_axis;
	t_vec	v_axis;

	// สร้างแกน u_axis และ v_axis
	// หาเวกเตอร์ U ที่ตั้งฉากกับ normal
	// ต้องสร้างแกนสองแกนที่ตั้งฉากกับ normal และตั้งฉากกันเอง เพื่อใช้เป็นแกนอ้างอิงสำหรับคำนวณพิกัด UV บนระนาบ
	arbitrary.x = 0.0f;
	arbitrary.y = 1.0f;
	arbitrary.z = 0.0f;
	// ถ้า normal เกือบขนานกับ (0,1,0)
	if (fabs(vec3_dot(hit.normal, arbitrary)) > 0.999f)
	{
		arbitrary.x = 1.0f;
		arbitrary.y = 0.0f;
		arbitrary.z = 0.0f;
	}
	u_axis = vec3_normalize(vec3_cross(hit.normal, arbitrary));
	v_axis = vec3_cross(hit.normal, u_axis);
	// เวกเตอร์จาก origin ไป hit point
	local = vec3_sub(hit.hit_p, hit.hit_shape->origin);
	// คำนวณ dot product กับแกน u, v แล้วคูณด้วย scale(float ยิ่งมาก ยิ่งลายเล็กลง (ซ้ำมากขึ้น)) เพื่อกำหนดจำนวนครั้งที่ลายซ้ำ
	*u = vec3_dot(local, u_axis) * 0.05f;
	*v = vec3_dot(local, v_axis) * 0.05f;
	// fmod ให้พิกัด UV อยู่ในช่วง [0,1] และทำให้ลาย texture ซ้ำ (tile) ได้อย่างไม่มีที่สิ้นสุดบนระนาบ
	clamp_uv(u, v);
}
