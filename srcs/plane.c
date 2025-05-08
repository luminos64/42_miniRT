#include "miniRT.h"

bool	pl_intersect(t_vector origin, t_vector direction, t_plane *plane, float *t, t_data *id)
{
	t_vector	normal;
	t_vector	temp_vector;
	float		denom;

	// กำหนดเวกเตอร์ตั้งฉากสมมติ (ถ้า plane->direction ขนานกับ (0,1,0) อาจต้องเปลี่ยน)
	if (plane->direction.z > -1.0f && plane->direction.z < 1.0f )
		plane->direction.z = id->temp.x;
		// plane->direction.x = p
	// plane->direction.y += id->temp.y;
	// plane->direction.z += id->temp.z;

	printf("x %f	y %f	z %f\n", plane->direction.x, plane->direction.y, plane->direction.z);
	temp_vector = (t_vector){plane->direction.y, plane->direction.x, 0.0f};
	normal = vec3_normalize(vec3_cross(plane->direction, temp_vector));
	// ถ้า denom ใกล้ 0 แสดงว่ารังสีขนานกับระนาบ ไม่มีจุดตัด
	denom = vec3_dot(direction, normal);
	if (fabsf(denom) < 1e-6f)
		return (false);
		// คำนวณเวกเตอร์จาก origin รังสีถึงจุดบนระนาบ
	temp_vector = vec3_sub(plane->origin, origin);

	// คำนวณ t ตามสูตร t = (C - O)·N / D·N
	denom = vec3_dot(temp_vector, normal) / denom;

	// ถ้า t < 0 จุดตัดอยู่ด้านหลังจุดกำเนิดรังสี ไม่สนใจ
	if (denom < 0)
		return false;

	// เก็บค่า t ที่ตำแหน่งที่ชี้
	*t = denom;
	// printf("ddddd\n");
	return (true);
}
