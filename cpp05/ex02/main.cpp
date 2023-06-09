#include <cstdlib>
#include <exception>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main() {
	std::cout << "========== ==========" << std::endl;
	std::cout << "Lets start with some basic tests" << std::endl;
	std::cout << "ShrubberyCreationForm" << std::endl;
	std::cout << "========== ==========" << std::endl;
	
	ShrubberyCreationForm* f = new ShrubberyCreationForm("SCF");
	if (!f)
		return 1;
	std::cout << *f;
	Bureaucrat b("carlos", 1);
	std::cout << b << std::endl;

	std::cout << "carlos will have no problem executing this form" << std::endl;

	b.signForm(*f);
	b.executeForm(*f);
	std::cout << "========== ==========" << std::endl;
	system("cat SCF_shrubbery");
	std::cout << "========== ==========" << std::endl;
	delete f;
	std::cout << "========== ==========" << std::endl;
	std::cout << "RobotomyRequestForm" << std::endl;
	std::cout << "========== ==========" << std::endl;
	RobotomyRequestForm* f2 = new RobotomyRequestForm("RRF");
	if (!f2)
		return 2;
	std::cout << *f;
	std::cout << "Lets execute this form a couple of times" << std::endl;
	b.signForm(*f);
	b.executeForm(*f);
	b.executeForm(*f);
	b.executeForm(*f);
	b.executeForm(*f);
	b.executeForm(*f);
	std::cout << "========== ==========" << std::endl;
	delete f2;
	std::cout << "========== ==========" << std::endl;
	std::cout << "PresidentialPardonForm" << std::endl;
	std::cout << "========== ==========" << std::endl;
	PresidentialPardonForm* f3 = new PresidentialPardonForm("PPF");
	if (!f3)
		return 3;
	std::cout << *f3;
	b.signForm(*f3);
	b.executeForm(*f);

	delete f3;
}
