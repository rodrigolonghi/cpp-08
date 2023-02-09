#include "easyfind.hpp"

int main (void) {
	std::vector<int>			intVec;
	std::vector<int>::iterator	itVec;

	for (int i = 0; i < 10; i++)
		intVec.push_back(i);

	std::cout << "\e[1;32mTest find value\n\e[0m";
	itVec = easyfind(intVec, 5);
	std::cout << *itVec << std::endl;

	std::cout << "\n\e[1;32mTest throw exception\n\e[0m";
	try {
		easyfind(intVec, -1);
	} catch (std::exception &e) {
		std::cout << e.what();
	}
}
