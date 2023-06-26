#ifndef __FIXED_HPP__
# define __FIXED_HPP__

#include <iostream>

class Fixed {

	private:
		int			_val;
		static int const	_fbits;

	public:
		Fixed();
		Fixed(int const n);
		Fixed(float const n);
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& rhs);
		bool operator>(const Fixed &rhs);
		bool operator>=(const Fixed &rhs);
		bool operator<(const Fixed &rhs);
		bool operator<=(const Fixed &rhs);
		bool operator==(const Fixed &rhs);
		bool operator!=(const Fixed &rhs);
		Fixed operator+(const Fixed &rhs);
		Fixed operator-(const Fixed &rhs);
		Fixed operator/(const Fixed &rhs);
		Fixed operator*(const Fixed &rhs);
		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator--();
		Fixed operator--(int);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
		int toInt(void) const;
		float toFloat(void) const;

		static Fixed& max(Fixed& a, Fixed& b);
		static Fixed& max(const Fixed& a, const Fixed& b);
		static Fixed& min(Fixed& a, Fixed& b);
		static Fixed& min(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif
