#include <iostream>
#include <string>

#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main(void)
{
	PhoneBook pb;

	while (true) {
		std::string line;
		std::cout << "Specify operation (ADD / SEARCH / EXIT)" << std::endl;
		std::getline(std::cin, line);
		if (std::cin.eof())
			return 1;
		if (line == "ADD")
			pb.add_contact();
		else if (line == "SEARCH")
			pb.display();
		else if (line == "EXIT")
			break;
		else
		 	std::cerr << "fatal: invalid option" << std::endl;
	}
}
