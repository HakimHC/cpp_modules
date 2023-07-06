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
		Span(Span&);
		Span& operator=(Span&);
		~Span();

		void	addNumber(int);
		int 	longestSpan();

		void	printVector();
};

#endif
