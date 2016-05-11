#ifndef VEC2_HPP
#define VEC2_HPP

class Vec2{
	public:
	Vec2();
	Vec2(float d, float e);
	float x; // Membervariablen
	float y;
		Vec2& operator+=(Vec2 const& v);
		Vec2& operator-=(Vec2 const& v);
		Vec2& operator*=(float v);
		Vec2& operator/=(float v);
};

 Vec2 operator+(Vec2 const& u, Vec2 const& v);
 Vec2 operator-(Vec2 const& u, Vec2 const& v);
 Vec2 operator*(Vec2 const& v, float s);
 Vec2 operator/(Vec2 const& v, float s);
 Vec2 operator*(float s, Vec2 const& v);

#endif 