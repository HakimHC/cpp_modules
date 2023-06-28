#ifndef __TESTFONT_HPP__
# define __TESTFONT_HPP__

#include <ostream>
#include <string>
#include <iostream>

#define GREEN "\e[0;32m"
#define PURPLE "\e[0;35m"
#define END "\e[0m"

class TestFont {

	private:
		std::string	_str;

	public:
		TestFont();
		TestFont(std::string const&, std::string color);
		TestFont(TestFont&);
		TestFont& operator=(TestFont&);
		~TestFont();

		std::string	getText() const;
		static void print(std::string msg, std::string color);

};

std::ostream& operator<<(std::ostream& os, TestFont msg);

#endif
