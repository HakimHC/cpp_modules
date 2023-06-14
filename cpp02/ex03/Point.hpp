#ifndef __POINT_HPP__
# define __POINT_HPP__

# include "Fixed.hpp"
#include <ostream>

class Point {

	private:
		Fixed& _x;
		Fixed& _y;
	public:
		Point();
		Point(Fixed&, Fixed&);
		Point(Point&);
		~Point();
		Point& 	operator=(Point&);

		Fixed&	getX() 	const;
		Fixed&	getY() 	const;
		void	setX(Fixed);
		void	setY(Fixed);
};

std::ostream& operator<<(std::ostream& os, Point &p);

#endif
