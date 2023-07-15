#include <cctype>
#include <exception>
#include <iostream>
#include <string>

#include "ScalarConverter.hpp"

/* Global variable of the required pseudo-literals */
static std::string pseudoLiterals[] = {
	"-inff",
	"+inff",
	"nanf",
	"-inf",
	"+inf",
	"nan"
};

/* Constructor - Destructor - Copy constructor - Copy assignment operator */
ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter& other) {
	(void) other;
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter& rhs) {
	(void) rhs;
	return *this;
}

/* Static utility functions */
static bool isInt(std::string& s) {
	for (size_t i = 0; i < s.size(); i++) {
		if (!std::isdigit(s[i]))
			return false;
	}
	return true;
}

static bool isFloat(std::string& s) {
	for (size_t i = 0; i < s.size(); i++) {
		if (s[i] == '.')
			continue;
		else if (i == s.size() - 1 && s[i] == 'f' && std::isdigit(s[i - 1]))
			continue;
		else if (!std::isdigit(s[i]))
			return false;
	}
	return true;
}

static bool isDouble(std::string& s) {
	for (size_t i = 0; i < s.size(); i++) {
		if (s[i] == '.')
			continue;
		else if (!std::isdigit(s[i]))
			return false;
	}
	return true;
}

static bool isPseudoLiteral(std::string& s) {
	for (size_t i = 0; i < _PSEUDO_LITERAL_ARRAY_SIZE; i++) {
		if (pseudoLiterals[i] == s)
			return true;
	}
	return false;
}

/* Member functions */
enum type ScalarConverter::determineType(std::string& s) {
	if (s.size() == 1 && !std::isdigit(s[0]))
		return CHAR;
	if (s.find(".") == std::string::npos) {
		if (!isInt(s) && !isPseudoLiteral(s))
			return UNKNOWN;
		if (isPseudoLiteral(s))
			return PSEUDOLITERAL;
		return INT;
	}
	if (isFloat(s))
		return FLOAT;
	else if (isDouble(s))
		return DOUBLE;
	return UNKNOWN;
}

void ScalarConverter::displayChar(std::string& s) {
	(void) s;
}

void ScalarConverter::convert(std::string& s) {
	/* ScalarConverter::displayChar(s); */
	std::string test[] = {"CHAR", "INT", "FLOAT", "DOUBLE", "UNKNOWN"};
	int en[] = {CHAR, INT, FLOAT, DOUBLE, UNKNOWN};

	int res = ScalarConverter::determineType(s);
	for (int i = 0; i < 5; i++)
	{
		if (en[i] == res)
			std::cout << test[i] << std::endl;
	}
}
