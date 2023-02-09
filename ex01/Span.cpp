#include "Span.hpp"
#include <limits.h>

Span::Span() : n(0) {}

Span::~Span() {}

Span::Span(unsigned int n) : n(n) {}

Span::Span(Span const &src) : n(src.n), content(src.content) {}

Span &Span::operator=(Span const &src) {
	this->n = src.n;
	this->content = src.content;
	return (*this);
}

void	Span::addNumber(int number) {
	if (this->content.size() == this->n)
		throw ExceededStoreException();
	this->content.push_back(number);
}

unsigned int	Span::shortestSpan() const {
	if (this->content.size() < 2)
		throw FewElementsException();

	unsigned int distance = INT_MAX;
	for (unsigned int i = 0; i < this->content.size(); i++) {
		for (unsigned int j = i + 1; j < this->content.size(); j++) {
			if((unsigned int)std::abs(this->content[i] - this->content[j]) < distance)
				distance = (std::abs(this->content[i] - this->content[j]));
		}
	}
	return (distance);
}

unsigned int	Span::longestSpan() const {
	if (this->content.size() < 2)
		throw FewElementsException();

	int largestNumber = *std::max_element(this->content.begin(), this->content.end());
	int smallestNumber = *std::min_element(this->content.begin(), this->content.end());
	return (std::abs(largestNumber - smallestNumber));
}

const char *Span::ExceededStoreException::what() const throw() {
	return ("Can't append more elements. Store is full\n");
}

const char *Span::FewElementsException::what() const throw() {
	return ("Not enough elements\n");
}
