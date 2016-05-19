#ifndef CIRCLE_HPP
#define CIRCLE_HPP



class Circle{
	public:
		Circle();
		//const& !
		Circle(float rad);

			void setradius(float r); //Set Radius
			float getradius();       // Get Radius

		bool operator< (Circle const& b);
		bool operator> (Circle const& b);		
		bool operator== (Circle const& b);

	private:
		float rad_;


			

};

#endif 

