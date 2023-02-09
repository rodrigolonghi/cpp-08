#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

class Span {
	private:
		unsigned int		n;
		std::vector<int>	content;

	public:
		Span();
		~Span();
		Span(unsigned int n);
		Span(Span const &src);
		Span &operator=(Span const &src);

		void			addNumber(int number);
		unsigned int	shortestSpan() const;
		unsigned int	longestSpan() const;

		class ExceededStoreException : public std::exception {
			virtual const char *what() const throw();
		};

		class FewElementsException : public std::exception {
			virtual const char *what() const throw();
		};
};

#endif
