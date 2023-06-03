#include <iostream>
#include <string>

std::string upper(std::string str)
{
	for (unsigned int i = 0; i < str.length(); i++)
		str[i] = std::toupper(str[i]);
	return str;
}

int	main(int argc, char **argv)
{
	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	}
	else {
		for (int i = 1; i < argc; i++) {
			std::cout << upper(argv[i]);
			i + 1 >= argc ? std::cout << std::endl : std::cout << " ";
		}
	}
	return 0;
}
