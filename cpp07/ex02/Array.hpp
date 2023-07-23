/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakahmed <hakahmed@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 05:52:14 by hakahmed          #+#    #+#             */
/*   Updated: 2023/07/24 01:06:26 by hakahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ARRAY_HPP__
# define __ARRAY_HPP__

#include <cstddef>
#include <exception>
# include <iostream>

template < class T >
class Array {
	
	private:
		T* 			_arr;
		unsigned int 	_size;

	public:
		Array() 	{this->_arr = new T[0]; this->_size = 0;}
		~Array() 	{delete[] this->_arr;}

		Array(unsigned int n) {
			this->_arr = new T[n];
			if (!this->_arr) {
				std::cerr << "fatal: cannot allocate memory" << std::endl;
				return;
			}
			this->_size = n;
		}
		Array(const Array& other) {
			this->_arr = new T[other._size];
			for (size_t i = 0; i < other._size; i++) {
				this->_arr[i] = other._arr[i];
			}
			this->_size = other._size;
		}
		Array& operator=(const Array& rhs) {
			delete[] this->_arr;
			this->_arr = new T[rhs._size];
			for (size_t i = 0; i < rhs._size; i++) {
				this->_arr[i] = rhs._arr[i];
			}
			this->_size = rhs._size;
      return *this;
		};

		T& operator[](int i) {
			if (i < 0 || (unsigned int) i >= this->_size) {
				throw std::runtime_error("fatal: index out of bounds");
				return this->_arr[0];
			}
			return this->_arr[i];
		}

		unsigned int size() const {
			return this->_size;
		}
};

#endif
