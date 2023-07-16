#ifndef __PMERGE_ME_HPP
# define __PMERGE_ME_HPP

# include <algorithm>
# include <string>
# include <vector>
# include <deque>

class PmergeMe {

	private:
		std::vector<unsigned int> 	_vec;
		std::deque<unsigned int> 	_dq;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe&);
		PmergeMe& operator=(const PmergeMe&);
		~PmergeMe();

		void parse(char *arr[]);

};

#endif
