#ifndef MAT2_HPP
#define MAT2_HPP //Praeprozessor Makro
#include "vec2.hpp"


class Mat2{
	public:
		Mat2(); //Default Constructor
		Mat2(float a, float b, float c, float d);
		float det() const;
		float a_; //Membervariablen
		float b_;
		float c_;
		float d_;

		Mat2& operator*=(Mat2 const& m);
		
};

Mat2 operator*(Mat2 const& m1, Mat2 const& m2);
Vec2 operator*(Mat2 const& m, Vec2 const& v);
Vec2 operator*(Vec2 const& v, Mat2 const& m);
Mat2 inverse(Mat2 const& m);
Mat2 transpose(Mat2 const& m);
Mat2 make_rotation_mat2(float phi);

#endif 

//Methoden sind Funktionen einer Klasse und Objekten zugeordnet