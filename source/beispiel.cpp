# include <cstdlib> //std::rand()
# include <vector> //std::vector<>
# include <list>   //std::list<>
# include <iostream> //std::cout
# include <iterator> //std::ostream_iterator<>
# include <algorithm> //std::reverse, std::generate
#define CATCH_CONFIG_RUNNER
#include <catch.hpp>


int main(int argc, char *argv[]){
	std::vector<int> v0(10); //Vektor mit 10 plaetzen

	for(std::vector<int>::iterator it = v0.begin(); //iteriert ueber den Vektor
		it != v0.end(); ++it){

		*it = std::rand();   //belegt Plaetze mit Zufallszahlen
	}
    //uebergibt die Werte von v0 an Ausgabe
	std::copy(std::begin(v0), std::end(v0),
		      std::ostream_iterator<int>(std::cout, "\n")); 

	std::list<int> l0(v0.size()); // legt Liste an fuer alle Werte aus v0
	std::copy(std::begin(v0), std::end(v0), std::begin(l0));

	std::list<int> l1(std::begin(l0), std::end(l0)); //legt neue Liste an mit Werten aus l0
	std::reverse(std::begin(l1), std::end(l1));  //dreht die Werte aus l1 um
	std::copy(std::begin(l1), std::end(l1),
		      std::ostream_iterator<int>(std::cout, "\n")); //gibt l1 umgedreht aus

	l1.sort(); //sortiert l1
	std::copy(l1.begin(), l1.end(),
		      std::ostream_iterator<int>(std::cout, "\n")); //gibt l1 sortiert aus

	std::generate(std::begin(v0), std::end(v0), std::rand); //bekommt Vektor uebergeben und belegt mit neuen Werten, Zufallszahlen
	std::copy(v0.rbegin(), v0.rend(),
		      std::ostream_iterator<int>(std::cout, "\n"));

	return Catch::Session().run(argc, argv);


}
