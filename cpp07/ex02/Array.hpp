/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakahmed <hakahmed@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 05:52:14 by hakahmed          #+#    #+#             */
/*   Updated: 2023/07/05 05:52:43 by hakahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ARRAY_HPP__
# define __ARRAY_HPP__

# include <iostream>

template < class T >
class Array {
	
	private:
		T* 		_arr;
		unsigned int 	_size;

	public:
		Array() {this->_arr = new T[5]; this->_size = 5;}
		Array(unsigned int n) {
			this->_arr = new T[n];
			if (!this->_arr) {
				std::cerr << "fatal: cannot allocate memory" << std::endl;
				return;
			}
			this->_size = n;
			for (unsigned int i = 0; i < n; i++) {
				this->_arr[i] = 0;
			}
		}
		/* Array(Array&); */
		/* Array& operator=(Array&) {}; */
		~Array() {}

		T& operator[](int i) {
			if (i < 0 || (unsigned int) i >= this->_size) {
				std::cerr << "Index out of bounds" << std::endl;
				return this->_arr[0];
			}
			return this->_arr[i];
		}

		unsigned int size() const {
			return this->_size;
		}

};

#endif
