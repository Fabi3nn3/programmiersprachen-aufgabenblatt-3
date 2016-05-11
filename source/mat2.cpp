#include "mat2.hpp"
#include "vec2.hpp"
#include <cmath>

Mat2::Mat2(): //Default
a_{1},
b_{0},
c_{0},
d_{1} {}

Mat2::Mat2(float a, float b, float c, float d): //User

a_{a},
b_{b},
c_{c},
d_{d} {}

Mat2& Mat2::operator*=(Mat2 const& m){
	float a_x = a_*m.a_ + b_*m.c_;
	float b_x = a_*m.b_ + b_*m.d_;
	float c_x = c_*m.a_ + d_*m.c_;
	float d_x = c_*m.b_ + d_*m.d_;
	a_ = a_x;
	b_ = b_x;
	c_ = c_x;
	d_ = d_x;

	return *this;
}

float Mat2::det() const{
	return a_*d_- b_*c_ ;
}


Mat2 operator*(Mat2 const& m1, Mat2 const& m2){
	Mat2 m3;
	m3.a_ = m1.a_*m2.a_ + m1.b_*m2.c_;
	m3.b_ = m1.a_*m2.b_ + m1.b_*m2.d_;
	m3.c_ = m1.c_*m2.a_ + m1.d_*m2.c_;
	m3.d_ = m1.c_*m2.b_ + m1.d_*m2.d_;
	
	return m3;

}

Vec2 operator*(Mat2 const& m, Vec2 const& v){
	Vec2 w;
	w.x = m.a_*v.x+m.b_*v.y;
	w.y = m.c_*v.x+m.d_*v.y;

	return w;
}

Vec2 operator*(Vec2 const& v, Mat2 const& m){
	Vec2 w;
	w.x = v.x*m.a_+v.y*m.b_;
	w.y = v.x*m.c_+v.y*m.d_;

	return w;

}
Mat2 inverse(Mat2 const& m){
	Mat2 inv;
	inv.a_ = (1/m.det())*m.d_;
	inv.b_ = (1/m.det())*-1*(m.b_);
	inv.c_ = (1/m.det())*-1*(m.c_);
	inv.d_ = (1/m.det())*(m.a_);

	return inv;
}
Mat2 transpose(Mat2 const& m){
	Mat2 trans;
	trans.a_= m.a_;
	trans.b_= m.c_;
	trans.c_= m.b_;
	trans.d_= m.d_;

	return trans;
}
Mat2 make_rotation_mat2(float phi){
	Mat2 rota;
	rota.a_ = cos(phi);
	rota.b_ = -1*sin(phi);
	rota.c_ = sin(phi);
	rota.d_ = cos(phi);

	return rota;

}