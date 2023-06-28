#include "TestFont.hpp"

TestFont::TestFont()
	: _str("default") {}
TestFont::TestFont(std::string const& msg, std::string color) {
	this->_str = color + msg + END;
}

TestFont::TestFont(TestFont& other)
	: _str(other._str) {}

TestFont& TestFont::operator=(TestFont& rhs) {
	if (this != &rhs) {
		this->_str = rhs._str;
	}
	return *this;
}

void TestFont::print(std::string msg, std::string color) {
	std::cout << color + msg + END << std::endl;
}

std::string TestFont::getText() const {
	return this->_str;
}

std::ostream& operator<<(std::ostream& os, TestFont msg) {
	os << msg.getText();
	return os;
}
