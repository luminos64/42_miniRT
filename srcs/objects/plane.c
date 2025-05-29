#include "miniRT.h"

bool	pl_intersect(t_vec ori, t_vec direction, t_plane *plane, float *t)
{
	t_vec	normal;
	t_vec	temp_vector;
	float	denominator;

	normal = vec3_normalize(plane->normal); // Normalize direction vector ของระนาบ
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
	// if (*t < 0)
	if (denominator < 0)
		return (false);

	// เก็บค่า t ที่ตำแหน่งที่ชี้
	*t = denominator;
	return (true);
}
