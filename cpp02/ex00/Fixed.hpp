#ifndef FIXED_H
# define FIXED_H

class Fixed {

	private:
		int val;
		static int const fbits;

	public:
		Fixed();
		Fixed(Fixed& other);
		Fixed& operator=(Fixed& other);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif
