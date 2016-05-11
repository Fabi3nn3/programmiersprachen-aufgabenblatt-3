#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"
#include "mat2.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
//#include "color.hpp"
#define M_PI   3.14159265358979323846 

TEST_CASE("TestDefaultConstructor","[TestDefaultConstructor]"){
	Vec2 v;
	REQUIRE(v.x == 0.0f);
	REQUIRE(v.y == 0.0f);
}

TEST_CASE("TestUserConstructor","[TestUserConstructor]"){
	Vec2 v{4.4,3.2};
	REQUIRE(v.x == 4.4f);
	REQUIRE(v.y == 3.2f);
	Vec2 u{1.0,0.0};
	REQUIRE(u.x == 1.0f);
	REQUIRE(u.y == 0.0f);
	Vec2 w{-2.0,-3.5};
	REQUIRE(w.x == Approx(-2.0));
	REQUIRE(w.y == Approx(-3.5)); 
}

TEST_CASE("TestOp +=", "[TestOp +=]"){
	Vec2 v1{4.4,3.2};
	Vec2 v2{1.3,2.5};
	v1+=v2 ;
	REQUIRE(v1.x == Approx(5.7f));
	REQUIRE(v1.y == Approx(5.7f));
	Vec2 v3{-1.0,2.3};
	Vec2 v4{-2.3,4.0};
	v3+=v4 ;
	REQUIRE(v3.x == Approx(-3.3f));
	REQUIRE(v3.y == Approx(6.3f));
	Vec2 v5{0.0,3.6};
	Vec2 v6{0.0,0.0};
	v5+=v6 ;
	REQUIRE(v5.x == Approx(0.0f));
	REQUIRE(v5.y == Approx(3.6f)); 
}

TEST_CASE("TestOp -=","[TestOp -=]"){
	Vec2 v1{4.4,3.2};
	Vec2 v2{1.3,2.5};
	v1-=v2;
	REQUIRE(v1.x == Approx(3.1f));
	REQUIRE(v1.y == Approx(0.7f));
	Vec2 v3{-4.4,-3.2};
	Vec2 v4{-1.3,-2.5};
	v3-=v4;
	REQUIRE(v3.x == Approx(-3.1f));
	REQUIRE(v3.y == Approx(-0.7f));
	Vec2 v5{0.0,3.0};
	Vec2 v6{-2.0,1.0};
	v5-=v6;
	REQUIRE(v5.x == Approx(2.0f));
	REQUIRE(v5.y == Approx(2.0f));
}

TEST_CASE("TestOp *=","[TestOp *=]"){
	Vec2 v1{4.4,3.2};
	Vec2 v2{1.3,2.5};
	Vec2 v3{3.0,4.0};
	v1*=1.0f;
	REQUIRE(v1.x == Approx(4.4f));
	REQUIRE(v1.y == Approx(3.2f));
	v2*=2.0f;
	REQUIRE(v2.x == Approx(2.6f));
	REQUIRE(v2.y == Approx(5.0f));
	v3*=3.3f;
	REQUIRE(v3.x == Approx(9.9f));
	REQUIRE(v3.y == Approx(13.2f));
}

TEST_CASE("TestOp /","[TestOp /]"){
	Vec2 v1{4.4,3.2};
	Vec2 v2{1.3,2.5};
	Vec2 v3{9.0,6.0};
	v1 /= 2.0f;
	REQUIRE(v1.x == Approx(2.2f));
	REQUIRE(v1.y == Approx(1.6f));
	v2 /= 1.0f;
	REQUIRE(v2.x == Approx(1.3f));
	REQUIRE(v2.y == Approx(2.5f));
	v3 /= 3.0f;
	REQUIRE(v3.x == Approx(3.0f));
	REQUIRE(v3.y == Approx(2.0f));
}

TEST_CASE("TestZwei+","[TestZwei+]"){
	Vec2 v{4.4,3.2};
	Vec2 u{1.3,2.5};
	Vec2 w=u+v;
	REQUIRE(w.x == Approx(5.7));
	REQUIRE(w.y == Approx(5.7));
	Vec2 a{-2.0,3.0};
	Vec2 b{3.0,3.0};
	Vec2 c=a+b;
	REQUIRE(c.x == Approx(1.0f));
	REQUIRE(c.y == Approx(6.0f));
	Vec2 d{0.0,4.0};
	Vec2 e{0.0,3.0};
	Vec2 f=d+e;
	REQUIRE(f.x == Approx(0.0f));
	REQUIRE(f.y == Approx(7.0f));
}

TEST_CASE("TestZwei-","[TestZwei-]"){
	Vec2 v{4.4,3.2};
	Vec2 u{1.3,2.5};
	Vec2 w=v-u;
	REQUIRE(w.x == Approx(3.1));
	REQUIRE(w.y == Approx(0.7));
	Vec2 a{-2.0,3.0};
	Vec2 b{3.0,3.0};
	Vec2 c=a-b;
	REQUIRE(c.x == Approx(-5.0f));
	REQUIRE(c.y == Approx(0.0f));
	Vec2 d{0.0,4.0};
	Vec2 e{0.0,3.0};
	Vec2 f=d-e;
	REQUIRE(f.x == Approx(0.0f));
	REQUIRE(f.y == Approx(1.0f));
}

TEST_CASE("TestZwei*","[TestZwei*]"){
	Vec2 v{4.4,3.2};
	float s = 2.0f;
	Vec2 w=v*s;
	REQUIRE(w.x == Approx(8.8));
	REQUIRE(w.y == Approx(6.4));
	/*Vec2 u{3.0,6.0};
	Vec2 o=u*r;
	float r = 1.0f;
	REQUIRE(o.x == Approx(3.0f));
	REQUIRE(o.y == Approx(6.0f));*/
}

TEST_CASE("TestZwei/","[TestZwei/]"){
	Vec2 v{4.4,3.2};
	float s = 1.0;
	Vec2 w=v/s;
	REQUIRE(w.x == Approx(4.4));
	REQUIRE(w.y == Approx(3.2));
}

TEST_CASE("TestZwei*f","[TestZwei*f]"){
	Vec2 v{4.4,3.2};
	float s = 2.0;
	Vec2 w=s*v;
	REQUIRE(w.x == Approx(8.8));
	REQUIRE(w.y == Approx(6.4));
}

TEST_CASE("TestMat","[TestMat2]"){
	Mat2 m1;
	REQUIRE(m1.a_ == 1.0f);
	REQUIRE(m1.b_ == 0.0f);
	REQUIRE(m1.c_ == 0.0f);
	REQUIRE(m1.d_ == 1.0f);
	Mat2 m2(2.0,3.4,4.4,5.6);
	REQUIRE(m2.a_ == 2.0f);
	REQUIRE(m2.b_ == 3.4f);
	REQUIRE(m2.c_ == 4.4f);
	REQUIRE(m2.d_ == 5.6f);
}

TEST_CASE("TestMat2Op*","[TestMat2Op*]"){
	Mat2 m1{1.0f,2.0f,3.0f,4.0f};
	Mat2 m2{2.0f,3.0f,3.0f,2.0f};
	m1*=m2;
	REQUIRE(m1.a_ == 8.0f);
	REQUIRE(m1.b_ == 7.0f);
	REQUIRE(m1.c_ == 18.0f);
	REQUIRE(m1.d_ == 17.0f);
}

TEST_CASE("TestMat2O*","[TestMat2Op*]"){
	Mat2 m1{1.0f,2.0f,3.0f,4.0f};
	Mat2 m2{2.0f,3.0f,3.0f,2.0f};
	Mat2 m3=m1*m2;
	REQUIRE(m3.a_ == 8.0f);
	REQUIRE(m3.b_ == 7.0f);
	REQUIRE(m3.c_ == 18.0f);
	REQUIRE(m3.d_ == 17.0f);
}

TEST_CASE("TestDet","[TestDet]"){
	Mat2 m1{1.0f,2.0f,3.0f,4.0f};

	REQUIRE(m1.det() == -2.0f);
}

TEST_CASE("TestVecMa","[TestVecMa]"){
	Mat2 m1{1.0f,2.0f,3.0f,4.0f};
	Vec2 v{4.0f,3.0f};
	Vec2 w = m1 * v;
	REQUIRE( w.x == 10.0f);
	REQUIRE( w.y == 24.0f);

}

TEST_CASE("TestMaVec","[TestMaVec]"){
	Mat2 m1{1.0f,2.0f,3.0f,4.0f};
	Vec2 v{4.0f,3.0f};
	Vec2 w = v * m1;
	REQUIRE( w.x == 10.0f);
	REQUIRE( w.y == 24.0f);

}

TEST_CASE("TestInverse","[TestInverse]"){
	Mat2 m1{1.0f,2.0f,3.0f,4.0f};
	Mat2 inv = inverse(m1);

	REQUIRE( inv.a_ == -2.0f);
	REQUIRE( inv.b_ == 1.0f);
	REQUIRE( inv.c_ == 1.5f);
	REQUIRE( inv.d_ == -0.5f);
}

TEST_CASE("TestTrans","[TestTrans]"){
	Mat2 m1{1.0f,2.0f,3.0f,4.0f};
	Mat2 trans = transpose(m1);

	REQUIRE( trans.a_ == 1.0f);
	REQUIRE( trans.b_ == 3.0f);
	REQUIRE( trans.c_ == 2.0f);
	REQUIRE( trans.d_ == 4.0f);

}

TEST_CASE("TestRota","[TestRota]"){
	float phi = 1.0f;
	Mat2 rota = make_rotation_mat2(phi);

	REQUIRE( rota.a_ == Approx(0.540302f));
	REQUIRE( rota.b_ == Approx(-0.841471f));
	REQUIRE( rota.c_ == Approx(0.841471f));
	REQUIRE( rota.d_ == Approx(0.540302f));


}

TEST_CASE("TestCircleArea","[TestCircleArea]"){
	
	Circle kreis{{0.0,0.0},5.0f};
	REQUIRE(kreis.getradius() == Approx(5.0f));
	REQUIRE(kreis.area() == Approx(78.5398163f));
	REQUIRE(kreis.circum() == Approx(31.4159265));
	REQUIRE(kreis.diameter() == Approx(10.0f));
	kreis.setradius(6.66f);
	REQUIRE(kreis.getradius() == Approx(6.66f));

}

TEST_CASE("TestRectangle","[TestRectangle]"){
	Rectangle recht{{0.0,0.0},5.0f,6.0f};
	REQUIRE(recht.getheight() == Approx(5.0f));
	REQUIRE(recht.getlength() == Approx(6.0f));
	REQUIRE(recht.area() == Approx(30.0f));
	REQUIRE(recht.circum() == Approx(22.0f));
	REQUIRE(recht.diagonal() == Approx(7.81024968f));
	recht.setheight(6.66f);
	REQUIRE(recht.getheight() == Approx(6.66f));
	recht.setlength(7.77f);
	REQUIRE(recht.getlength() == Approx(7.77f));
	
}

TEST_CASE("TestInsideRec","[TestInsideRec]"){
	Rectangle w{};
	REQUIRE(w.is_inside({1.0f,1.0f}) == false);
	Rectangle w2{{2.3,4.5},{3.3},{3.6},{1.0,0.0,1.0}};
	REQUIRE(w2.is_inside({1.3f,2.3f}) == false);
}

TEST_CASE("TestInsideCirc","[TestInsideCirc]"){
	Circle c{};
	REQUIRE(c.is_inside({1.0f,1.0f}) == true);
}




int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
