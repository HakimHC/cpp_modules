#ifndef __SCALAR_CONVERTER_HPP__
# define __SCALAR_CONVERTER_HPP__

# include <string>

class ScalarConverter {
	public:
		ScalarConverter();
		ScalarConverter(ScalarConverter&);
		ScalarConverter& operator=(ScalarConverter&);
		~ScalarConverter();

		static void convert(std::string);
};

#endif
