#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "color.hpp"
#include "window.hpp"
#include "vec2.hpp"

class Rectangle{
	public:
		Rectangle();
		Rectangle(Vec2 v, float x, float y);
		Rectangle(Vec2 v, float x, float y, Color farbe);
		float x_;
		float y_;
		Vec2 v_;
		Color farbe_;

			void setheight(float x); //Set Hoehe
			void setlength(float y); //Set Laenge
			float getheight();       //Get Hoehe
			float getlength();       //Get Laenge
			float circum();          //Umfang
			float area();            //Flaecheninhalt
			float diagonal();        //Diagonale
			void draw(Window& win);
			void draw(Window& win, Color farbe);
			bool is_inside(Vec2 v);
		
};
#endif
