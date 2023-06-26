#ifndef __FIXED_HPP__
# define __FIXED_HPP__

class Fixed {

	private:
		int			_val;
		static int const	_fbits;

	public:
		Fixed();
		Fixed(Fixed& other);
		Fixed& operator=(Fixed& rhs);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif
