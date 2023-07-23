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
		typedef typename std::deque<T>::const_iterator const_iterator;
		typedef typename std::deque<T>::reverse_iterator reverse_iterator;
		typedef typename std::deque<T>::const_reverse_iterator const_reverse_iterator;

		iterator begin() { return this->c.begin(); }
		iterator end() { return this->c.end(); }

		reverse_iterator rbegin() { return this->c.rbegin(); }
		reverse_iterator rend() { return this->c.rend(); }

		const_iterator begin() const { return this->c.begin(); }
		const_iterator end() const { return this->c.end(); }

		const_reverse_iterator rbegin() const { return this->c.rbegin(); }
		const_reverse_iterator rend() const { return this->c.rend(); }
};

#endif
