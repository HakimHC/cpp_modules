#ifndef __PMERGE_ME_HPP
# define __PMERGE_ME_HPP

# include <algorithm>
#include <bits/types/clock_t.h>
# include <string>
# include <vector>
# include <deque>

enum containers {
	VECTOR,
	DEQUE
};

class PmergeMe {

	private:
		std::vector<unsigned int> 	_vec;
		std::deque<unsigned int> 	_dq;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe&);
		PmergeMe& operator=(const PmergeMe&);
		~PmergeMe();

		void 	parse(const char *arr[]);
		void	sortVector();
		void	sortDeque();

		void	print(enum containers type) const;

    double trackRunTimeVector();
    double trackRunTimeDeque();
};

#endif
