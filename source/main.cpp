#include <cstdlib>	//std::rand()
#include <vector>	//std::vector<>
#include <list>		//std::list<>
#include <iostream>	//std::cout
#include <iterator>	//std::ostream_iterator<>
#include <algorithm> //std::reserve, std::generate

int main ()
{
	std::vector<int> v0(10); //container (vector) v0 = int länge 10, container (list) l0,l1 = int,

	for (std::vector<int>::iterator it = v0.begin(); //v0 mit zufallszahlen //iterator (pointer)
		it != v0.end(); ++it) {
		*it = std::rand();
	}

//oder:
//for (auto& v : v0) {
//		v = std::rand();
//}
std::copy(std::begin(v0), std::end(v0), std::ostream_iterator<int>(std::cout, "\n")); 

std::list<int> l0(v0.size()); //l0 erstellung via vector
std::copy(std::begin(v0), std::end(v0), std::begin(l0));

std::list<int> l1(std::begin(l0), std::end(l0)); //Liste 
std::reverse(std::begin(l1), std::end(l1));
std::copy(std::begin(l1), std::end(l1),
	std::ostream_iterator<int>(std::cout, "\n"));

l1.sort();				//Sortiert die Liste
std::copy(l1.begin(), l1.end(),
	std::ostream_iterator<int>(std::cout, "\n"));

std::generate(std::begin(v0), std::end(v0), std::rand); //neue Zahlenwerte und umgekehrte Ausgabe
std::copy(v0.rbegin(), v0.rend(),
	std::ostream_iterator<int>(std::cout, "\n"));


return 0;
}