#ifndef FIXED_H
# define FIXED_H

#include <iostream>

class Fixed {

	private:
		int val;
		static int const fbits;

	public:
		Fixed();
		Fixed(int const n);
		Fixed(float const n);
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& rhs);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
		int toInt(void) const;
		float toFloat(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif
