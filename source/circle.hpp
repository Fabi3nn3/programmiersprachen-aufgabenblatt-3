#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"


class Circle{
	public:
		Circle();
		//const& !
		Circle(Vec2 v, float rad);
		Circle(Vec2 v, float rad, Color farbe);
		
		float rad_;
		Vec2 v_;
		Color farbe_;

			void setradius(float r); //Set Radius
			float getradius();       // Get Radius
			float area() const;			  //gibt Flaeche
			float circum();		  //gibt Umkreis
			float diameter();        //gibt Durchmesser
			void draw(Window& win);
			void draw(Window& win,Color farbe);
			bool is_inside(Vec2 v);

};

#endif 

//Operator ueberladen,d.h Methode oder fkt definieren die dem Operator Aufruf entspricht, operator dahinter ohne Leerzeichen das Operatorzeichen
//Rueckgabewert identisch mit Datentyp 1.Parameter, mehrmalige Anwendug eines Operators in einer Zeile
//ausserhalb der Klasse eine freistehende Funktion deklariert