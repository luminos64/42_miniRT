#include "miniRT.h"

t_vec	procedural_ckeckerboard(float u, float v, int scale)
{
	t_vec	color;
	int		cal;

	cal = (int)floor(u * scale) + (int)floor(v * scale);
	// ดำ
	color.x = 0.0f;
	color.y = 0.0f;
	color.z = 0.0f;
	// ขาว
	if (cal % 2 == 0)
	{
		color.x = 1.0f;
		color.y = 1.0f;
		color.z = 1.0f;
	}
	return (color);
}

void	clamp_uv(float *u, float *v)
{
	// ทำให้ u, v อยู่ในช่วง [0,1]
	*u = fmod(*u, 1.0f);
	if (*u < 0)
		*u = *u + 1.0f;
	*v = fmod(*v, 1.0f);
	if (*v < 0)
		*v = *v + 1.0f;
}

static float	get_height(t_data *id, float u, float v)
{
	int		int_u;
	int		int_v;
	uint8_t	pixel;

	// แปลงค่า UV เป็นตำแหน่งพิกเซลใน texture คำนวณตำแหน่งพิกเซลใน texture จาก UV
	int_u = (int)(u * (id->b_texture->width - 1));
	int_v = (int)(v * (id->b_texture->height - 1));
	// อ่านค่าความสูงจาก texture
	// ดึงค่าความสูง (เช่น ค่า grayscale) จากตำแหน่งพิกเซลนั้น
	pixel = id->b_texture->pixels[(int_v * id->b_texture->width + int_u) * 4];
	return (pixel / 255.0f);
}

static t_vec	adj_normal(t_hit hit, float u, float v)
{
	t_vec	tangent;
	t_vec	bitangent;
	t_vec	arbitrary;
	t_vec	res;
	float	bump_scale;

	// หา tangent และ bitangent vectors บนพื้นผิว
	// สร้าง tangent vector ที่ตั้งฉากกับ normal (เลือกเวกเตอร์ arbitrary)
	arbitrary = (t_vec){0.0f, 1.0f, 0.0f};
	if (fabs(vec3_dot(hit.normal, arbitrary)) > 0.999f)
		arbitrary = (t_vec){1.0f, 0.0f, 0.0f};

	tangent = vec3_normalize(vec3_cross(arbitrary, hit.normal));
	bitangent = vec3_cross(hit.normal, tangent);

	// ปรับ normal ด้วย gradient และ bump scale
	// ปรับขนาด bump effect ได้ตามต้องการ
	bump_scale = 2.0f;

	res.x = hit.normal.x - bump_scale * (u * tangent.x + v * bitangent.x);
	res.y = hit.normal.y - bump_scale * (u * tangent.y + v * bitangent.y);
	res.z = hit.normal.z - bump_scale * (u * tangent.z + v * bitangent.z);

	res = vec3_normalize(res);
	return (res);
}

t_vec	bump_mapping(t_data *id, float u, float v, t_hit hit)
{
	t_vec	res;
	t_vec	height_u;
	t_vec	height_v;
	float	delta;

	delta = 1.0f / id->b_texture->width;
	height_u.x = get_height(id, u - delta, v);
	height_u.y = get_height(id, u + delta, v);
	height_v.x = get_height(id, u, v - delta);
	height_v.y = get_height(id, u, v + delta);

	// คำนวณอนุพันธ์ (gradient) ของ bump map
	res.x = (height_u.y - height_u.x);
	res.y = (height_v.y - height_v.x);
	res = adj_normal(hit, res.x, res.y);
	return (res);
}
