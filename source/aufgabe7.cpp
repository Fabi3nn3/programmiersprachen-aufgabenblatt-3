# define CATCH_CONFIG_RUNNER
# include <catch.hpp>
# include <cmath>
# include <algorithm>
# include "circle.hpp"

bool is_odd(int i){
	return (i % 2) != 0;  
}

bool is_even(int i){
	return(i % 2) == 0;
}

template <typename container, typename datype>
	void swap(datype first, datype second, container& K){
		auto temp = K[first];
		K[first]=K[second];
		K[second]=temp;
	}

template <typename container, typename funktion>

	container filter(container const& K, funktion const& F){

		container newK;
		for(auto i : K){

			if(F(i))newK.push_back(i);

		}
	return newK;
	}


TEST_CASE("Lambda","[Lambda]"){
	std::vector<Circle> circle(15);

		for(int i = 0; i < 15; ++i){
			circle[i].setradius(rand());
		}

	std::sort(circle.begin(),circle.end(), [] (Circle d, Circle e) {return d.getradius() < e.getradius();});

	REQUIRE(std::is_sorted(circle.begin(), circle.end()));
}

TEST_CASE ("describe_factorial","[aufgabe7]")
{
	std::vector<Circle> circle(10); //Vektor mit 100 plaetzen

		for(int i = 0; i < 10; ++i){
			circle[i].setradius(rand());
		}

	std::sort(circle.begin(),circle.end());

	REQUIRE(std::is_sorted(circle.begin(),circle.end()));
}

TEST_CASE("describe_swap","[aufgabe8]"){
	std::vector<char> hallo{'h','a','l','l','o'};
	swap(0,4,hallo);
	swap(1,2,hallo);
	REQUIRE(hallo[0]=='o');
	REQUIRE(hallo[4]=='h');
	REQUIRE(hallo[1]=='l');
	REQUIRE(hallo[2]=='a');
}

TEST_CASE("Vecaddieren","[Vecaddieren]"){
	std::vector<int>v1 {1 ,2 ,3 ,4 ,5 ,6 ,7 ,8 ,9};
    std::vector<int>v2 {9 ,8 ,7 ,6 ,5 ,4 ,3 ,2 ,1};
	std::vector<int>v3 (9);

	std::transform(v1.begin(),v1.end(),v2.begin(),v3.begin(), [] (int d, int e) {return d + e;});

	REQUIRE(std::all_of (v3.begin(), v3.end(), [] (int a) {return a == 10;}));
}

TEST_CASE("Filter","[Filter]"){
	std::vector<int>v1 {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
	std::vector<int> alleven = filter (v1, is_even );

	REQUIRE(std::all_of(alleven.begin(),alleven.end(), is_even));

}


int main(int argc,char*argv[])
{
return Catch::Session().run(argc,argv );
}