#ifndef __SPAN_HPP__
# define __SPAN_HPP__

#include <vector>

class Span {
	private:
		unsigned int 		_N;
		std::vector<int> 	_vec;

	public:
		Span();
		Span(unsigned int);
		Span(const Span&);
		Span& operator=(Span&);
		~Span();

		void	addNumber(int);
		int 	longestSpan();
		int 	shortestSpan();
		void	addRange(std::vector<int>::iterator first, std::vector<int>::iterator last);

		void	printVector();
};

#endif
