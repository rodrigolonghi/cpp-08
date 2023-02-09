#include "Span.hpp"

int main() {
	Span 	sp = Span(5);
	Span	shortSpan(5);
	Span	errorSpan(100);
	Span	regularSpan(10000);

	for (int i = 0; i < 5; i++)
		shortSpan.addNumber(i);
	for (int i = 0; i < 10000; i++)
		regularSpan.addNumber(rand());

	std::cout << "\e[1;32mTest get shortest span\n\e[1;34mOn shortSpan\n\e[0m";
	std::cout << shortSpan.shortestSpan() << std::endl;
	std::cout << "\e[1;34mOn regularSpan\n\e[0m";
	std::cout << regularSpan.shortestSpan() << std::endl;

	std::cout << "\e[1;32m\nTest get longest span\n\e[1;34mOn shortSpan\n\e[0m";
	std::cout << shortSpan.longestSpan() << std::endl;
	std::cout << "\e[1;34mOn regularSpan\n\e[0m";
	std::cout << regularSpan.longestSpan() << std::endl;

	std::cout << "\e[1;31m\nTest throw exception\n\e[0;31mTry add more elements when storage is full\n\e[0m";
	try {
		shortSpan.addNumber(10);
	} catch (std::exception &e) {
		std::cout << e.what();
	}
	std::cout << "\e[0;31m\nTry get shortest span when has no element\n\e[0m";
	try {
		errorSpan.shortestSpan();
	} catch (std::exception &e) {
		std::cout << e.what();
	}

	std::cout << "\e[1;32m\nSubject tests:\e[0m\n";
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0;
}
