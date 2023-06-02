#include <string>
#include <iostream>

int	main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF = str;

	std::cout << "======= MEMORY ADDRESS =======" << std::endl << std::endl;

	std::cout << "str:	\t" << &str << std::endl;
	std::cout << "stringPTR:\t" << stringPTR << std::endl;
	std::cout << "stringREF:\t" << &stringREF << std::endl << std::endl;

	std::cout << "======= VALUES =======" << std::endl << std::endl;

	std::cout << "str:	\t" << str << std::endl;
	std::cout << "stringPTR:\t" << *stringPTR << std::endl;
	std::cout << "stringREF:\t" << stringREF << std::endl;
	return 0;
}
