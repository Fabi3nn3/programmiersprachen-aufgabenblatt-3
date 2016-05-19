# define CATCH_CONFIG_RUNNER
# include <catch.hpp>
# include <cmath>
# include <algorithm>

bool is_odd(int i){
	return (i % 2) != 0;  
}

bool is_even(int i){
	return(i % 2) == 0;
}


TEST_CASE ("describe_factorial","[aufgabe3]")
{
std::vector<unsigned int> v0(100); //Vektor mit 100 plaetzen

	for(std::vector<unsigned int>::iterator it = v0.begin(); //iteriert ueber den Vektor
		it != v0.end(); ++it){

		*it = std::rand() % 101;   //belegt Plaetze mit Zufallszahlen
	}


v0.erase(std::remove_if(v0.begin(), v0.end(), is_odd), v0.end() );

REQUIRE(std::all_of(v0.begin(),v0.end(),is_even ));
}

int main(int argc,char*argv[])
{
return Catch::Session().run(argc,argv );
}