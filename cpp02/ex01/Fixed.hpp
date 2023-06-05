#ifndef FIXED_H
# define FIXED_H

class Fixed {

	private:
		int val;
		static int const fbits;

	public:
		Fixed();
		Fixed(int const n);
		Fixed(float const n);
		Fixed(Fixed& other);
		Fixed& operator=(Fixed& rhs);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
		int toInt(void) const;
		float toFloat(void) const;
};

#endif
