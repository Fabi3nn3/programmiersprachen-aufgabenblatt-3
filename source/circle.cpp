//#include "mat2.hpp"
//#include "vec2.hpp"
#include "circle.hpp"
//#include "color.hpp"
//#include "window.hpp"
#include <cmath>
#define M_PI   3.14159265358979323846 


Circle::Circle():
rad_{50},
v_{25,35},
farbe_{0.0,0.0,0.0} {}

Circle::Circle(Vec2 v, float rad):
rad_{rad},
v_{v},
farbe_{0.0,0.0,0.0}{}

Circle::Circle(Vec2 v, float rad, Color farbe):
rad_{rad},
v_{v},
farbe_{farbe} {}

void Circle::setradius(float r){
	rad_=r;
}

float Circle::getradius(){
	return rad_;
}
float Circle::area(){
	float a = M_PI*rad_*rad_;
	return a;
}

float Circle::circum(){
	float u = 2*M_PI*rad_;
	return u;
}

float Circle::diameter(){
	float d = 2*rad_;
	return d;
}



void Circle::draw(Window& win){

	for(float i=0.0; i<2*M_PI; i+=0.005){
		win.draw_point(v_.x+rad_*cos(i),v_.y+rad_*sin(i),
			           farbe_.r_,farbe_.g_,farbe_.b_);
	}

}

void Circle::draw(Window& win, Color farbe){

	for(float i=0.0; i<2*M_PI; i+=0.005){
		win.draw_point(v_.x+rad_*cos(i),v_.y+rad_*sin(i),
			           farbe.r_,farbe.g_,farbe.b_);
	}

}

bool Circle::is_inside(Vec2 v){

	if(sqrt((v.x-v_.x)*(v.x-v_.x)+(v.y-v_.y)*(v.y-v_.y)) < rad_ ) return true;
	else return false;
}


//Berechnung fuer Radius, Flaeche, Umkreis, Durchmesser
//Berechnung Rectangle x,y Vektor; sethigh, setwidth; gethigh, getwith, Umfang, flache

	