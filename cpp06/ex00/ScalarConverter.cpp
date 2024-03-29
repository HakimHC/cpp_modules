#include <cstdlib>
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
			return true;
		else if (!std::isdigit(s[i]) || (i == s.size() - 1 && s[i] != 'f'))
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
	std::cout << "char: " << "'" << s[0] << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(s[0]) << std::endl;
	std::cout << "float: " << static_cast<float>(s[0]) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<int>(s[0]) << ".0" << std::endl;
}

void ScalarConverter::displayInt(std::string& s) {
	std::string nond = "";
	int converted = std::atoi(s.c_str());

	if (!std::isprint(converted) || !isascii(converted))
		nond = "Non displayable";
	std::cout << "char: ";
	if (nond.empty())
		std::cout << "'" << static_cast<char>(converted) << "'" << std::endl;
	else
	 	std::cout << nond << std::endl;
	std::cout << "int: " << converted << std::endl;
	std::cout << "float: " << static_cast<float>(converted) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<int>(converted) << ".0" << std::endl;
}

void ScalarConverter::displayFloat(std::string& s) {
	std::string nond = "";
	float converted = std::atof(s.c_str());

	if (!std::isprint(static_cast<int>(converted)) || !isascii(static_cast<int>(converted)))
		nond = "Non displayable";
	std::cout << "char: ";
	if (nond.empty())
		std::cout << "'" << static_cast<char>(converted) << "'" << std::endl;
	else
	 	std::cout << nond << std::endl;
	std::cout << "int: " << static_cast<int>(converted) << std::endl;
	std::cout << "float: " << s << std::endl;
	std::cout << "double: " << static_cast<double>(converted) << std::endl;
}

void ScalarConverter::displayDouble(std::string& s) {
	std::string nond = "";
	double converted = std::atof(s.c_str());

	if (!std::isprint(static_cast<int>(converted)) || !isascii(static_cast<int>(converted)))
		nond = "Non displayable";
	std::cout << "char: ";
	if (nond.empty())
		std::cout << "'" << static_cast<char>(converted) << "'" << std::endl;
	else
	 	std::cout << nond << std::endl;
	std::cout << "int: " << static_cast<int>(converted) << std::endl;
	std::cout << "float: " << s << "f" << std::endl;
	std::cout << "double: " << s << std::endl;
}

void ScalarConverter::displayPseudoLiteral(std::string& s) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	
	int pos;
	int factor;
	for (pos = 0; pos < _PSEUDO_LITERAL_ARRAY_SIZE; pos++) {
		if (pseudoLiterals[pos] == s)
			break;
	}
	factor = pos >= 3 ? 3 : -3;
	std::cout << "float: " << (pos >= 3 ? pseudoLiterals[pos - factor] : pseudoLiterals[pos]) << std::endl;
	std::cout << "double: " << (pos >= 3 ? pseudoLiterals[pos] : pseudoLiterals[pos - factor]) << std::endl;
}

void ScalarConverter::displayUnknown() {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

void ScalarConverter::convert(std::string& s) {

	enum type type = ScalarConverter::determineType(s);

	switch (type) {
		case CHAR:
			ScalarConverter::displayChar(s);
			break;
		case INT:
			ScalarConverter::displayInt(s);
			break;
		case FLOAT:
			ScalarConverter::displayFloat(s);
			break;
		case DOUBLE:
			ScalarConverter::displayDouble(s);
			break;
		case PSEUDOLITERAL:
			ScalarConverter::displayPseudoLiteral(s);
			break;
		default:
			ScalarConverter::displayUnknown();

	}
}
