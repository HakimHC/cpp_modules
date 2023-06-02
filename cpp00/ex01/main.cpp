#include <iostream>
#include <string>

#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main(void)
{
	PhoneBook pb;

	while (true) {
		std::cout << "Specify operation (ADD / DISPLAY / EXIT)" << std::endl;
		std::string line;
		std::getline(std::cin, line);
		if (line == "ADD")
			pb.add_contact();
		else if (line == "DISPLAY")
			pb.display();
		else if (line == "EXIT")
			break;
		else
		 	std::cerr << "fatal: invalid option" << std::endl;
	}
}
