#ifndef __SCALAR_CONVERTER_HPP__
# define __SCALAR_CONVERTER_HPP__

# include <string>

enum type {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDOLITERAL,
	UNKNOWN
};

#define _PSEUDO_LITERAL_ARRAY_SIZE 6

class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter&);
		ScalarConverter& operator=(ScalarConverter&);
		~ScalarConverter();

		static enum type determineType(std::string&);

		static void displayChar(std::string&);
		static void displayInt(std::string&);
		static void displayFloat(std::string&);
		static void displayDouble(std::string&);

		static void displayUnknown();

	public:
		static void convert(std::string&);
};

#endif
