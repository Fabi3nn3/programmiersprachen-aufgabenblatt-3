#include "rectangle.hpp"
#include "color.hpp"
#include "window.hpp"
#include "vec2.hpp"
#include <cmath>

Rectangle::Rectangle():
x_{3},
y_{4},
v_{3,3},
farbe_{0,0,0}{}

Rectangle::Rectangle(Vec2 v, float x, float y):
x_{x},
y_{y},
v_{v},
farbe_{0,0,0}{}


Rectangle::Rectangle(Vec2 v,float x, float y, Color farbe):
x_{x},
y_{y},
v_{v},
farbe_{farbe}{}

void Rectangle::setheight(float h){
	x_=h;
}

float Rectangle::getheight(){
	return x_;
}

void Rectangle::setlength(float l){
	y_=l;
}

float Rectangle::getlength(){
	return y_;
}

float Rectangle::circum(){
	float c = 2*x_+2*y_ ;
	return c;
}

float Rectangle::area(){
	float a = x_*y_;
	return a;
}

float Rectangle::diagonal(){
	float d = sqrt(x_*x_+y_*y_);
	return d;
}

void Rectangle::draw(Window& win){
	win.draw_line(v_.x,v_.y,
				  x_+v_.x,v_.y,
				  farbe_.r_,farbe_.g_,farbe_.b_);

	win.draw_line(x_+v_.x,v_.y,
		          x_+v_.x,y_+v_.y,
		          farbe_.r_,farbe_.g_,farbe_.b_);

	win.draw_line(x_+v_.x,y_+v_.y,
		          v_.x,y_+v_.y,
		          farbe_.r_,farbe_.g_,farbe_.b_);

	win.draw_line(v_.x,y_+v_.y,
		          v_.x,v_.y,
		          farbe_.r_,farbe_.g_,farbe_.b_);

}

void Rectangle::draw(Window& win, Color farbe){
	win.draw_line(v_.x,v_.y,
				  x_+v_.x,v_.y,
				  farbe.r_,farbe.g_,farbe.b_);

	win.draw_line(x_+v_.x,v_.y,
		          x_+v_.x,y_+v_.y,
		          farbe.r_,farbe.g_,farbe.b_);

	win.draw_line(x_+v_.x,y_+v_.y,
		          v_.x,y_+v_.y,
		          farbe.r_,farbe.g_,farbe.b_);

	win.draw_line(v_.x,y_+v_.y,
		          v_.x,v_.y,
		          farbe.r_,farbe.g_,farbe.b_);

}

bool Rectangle::is_inside(Vec2 v){
	if(v.x >= v_.x && v.y >= v_.y && v.x <= v_.x+x_ && v.y <= v_.y+y_) return true;
	else return false;
}