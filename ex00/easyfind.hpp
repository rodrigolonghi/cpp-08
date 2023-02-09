#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <vector>
#include <iostream>
#include <algorithm>

class ValueNotFoundException : public std::exception {
	virtual const char *what() const throw() {
		return "Value not found\n";
	}
};

template<typename T>
typename T::iterator	easyfind(T &container, int value) {
	typename T::iterator result;
	result = find(container.begin(), container.end(), value);
	if (result == container.end())
		throw ValueNotFoundException();
	return result;
};

#endif
