#ifndef __MSTACK_HPP__
# define __MSTACK_HPP__

# include <algorithm>
# include <stack>
# include <list>

template < typename T >
class MutantStack : public std::stack<T> {
	public:
		MutantStack<T>() {}
		MutantStack<T>(const MutantStack<T>& other) {
			*this = other;
		}
		MutantStack<T>& operator=(const MutantStack<T>& rhs) {
			(void) rhs;
			return *this;
		}
		~MutantStack<T>() {}

		typedef typename std::deque<T>::iterator iterator;

		iterator begin() { return this->c.begin(); }
		iterator end() { return this->c.end(); }

		iterator rbegin() { return this->c.rbegin(); }
		iterator rend() { return this->c.rend(); }
};

#endif
