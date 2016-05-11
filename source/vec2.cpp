#include "vec2.hpp"

Vec2::Vec2(): //Standartkonstruktor, mit 0 initialisiert
x{0.0f},
y{0.0f} {} //weil {} leer, kein Destruktor benoetigt

Vec2::Vec2(float d, float e): //Konstruktor mit uebergabe Parameter

x{d},
y{e} {}

Vec2& Vec2::operator+=(Vec2 const& v){
	x += v.x ;
	y += v.y ;

	return *this;

}

Vec2& Vec2::operator-=(Vec2 const& v){
	x -= v.x ;
	y -= v.y ;

	return *this;
}

Vec2& Vec2::operator*=(float v){
	x *= v ;
	y *= v ;

	return *this;
}

Vec2& Vec2::operator/=(float v){
	x /= v ; 
	y /= v ;

	return *this;
}

Vec2 operator+(Vec2 const& u, Vec2 const& v){

	Vec2 F;
	F.x= u.x+v.x;
	F.y= u.y+v.y;

	return F;

}

Vec2 operator-(Vec2 const& u, Vec2 const& v){
	Vec2 F;
	F.x=u.x-v.x;
	F.y=u.y-v.y;

	return F;
}

 Vec2 operator*(Vec2 const& v, float s){
 	Vec2 F;
 	F.x=v.x*s;
 	F.y=v.y*s;

 	return F;
 }

 Vec2 operator/(Vec2 const& v, float s){
 	Vec2 F;
 	F.x=v.x/s;
 	F.y=v.y/s;

 	return F;
 }

 Vec2 operator*(float s, Vec2 const& v){
 	Vec2 F;
 	F.x=s*v.x;
 	F.y=s*v.y;

 	return F;
 }