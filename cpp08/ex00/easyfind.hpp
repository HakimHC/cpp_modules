#ifndef __EASYFIND_HPP__
# define __EASYFIND_HPP__

#include <cstddef>
#include <exception>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>

template < typename T >
typename T::iterator easyfind(T& arr, int toFind) {

	typename T::iterator it = std::find(arr.begin(), arr.end(), toFind);
	if (it == arr.end() && *it != toFind) {
		throw std::runtime_error("Cannot find element in container");
	}
	return it;
}

#endif
