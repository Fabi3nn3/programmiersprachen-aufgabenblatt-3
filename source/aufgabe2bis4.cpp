# include <cstdlib> //std::rand()
# include <vector> //std::vector<>
# include <list>   //std::list<>
# include <iostream> //std::cout
# include <iterator> //std::ostream_iterator<>
# include <algorithm> //std::reverse, std::generate
# include <set>
# include <map>
#define CATCH_CONFIG_RUNNER
#include <catch.hpp>

int main(int argc, char *argv[]){
	std::list<unsigned int> l0(100); //Vektor mit 100 plaetzen

	for(std::list<unsigned int>::iterator it = l0.begin(); //iteriert ueber den Vektor
		it != l0.end(); ++it){

		*it = rand() % 101;   //belegt Plaetze mit Zufallszahlen von 0 bis 100
	}

	std::vector<unsigned int>v0(l0.size()); //Erstellt Vektor
	std::copy(std::begin(l0), std::end(l0), std::begin(v0)); //kopiert Liste 

	std::set<unsigned int>set_list(std::begin(l0), std::end(l0));
	std::cout<<"Es gibt  " <<set_list.size() << "  unterschiedliche Zahlen" <<std::endl;

	//Zahlen ausgeben die nicht in der Liste sind
	for(int i = 0; i<= 100; ++i){
		if(set_list.count(i) == false){
			std::cout << i << std::endl;
		}
	}

	//Map erstellt und Haufigkeiten fuer i
	std::map<unsigned int, unsigned int>map_list;
	for(auto &i: l0){
		++map_list[i];
	}

	for(int i = 0; i<= 100; ++i){
		std::cout << i << " : " << map_list[i] << std::endl;
	}



	return Catch::Session().run(argc, argv);


}