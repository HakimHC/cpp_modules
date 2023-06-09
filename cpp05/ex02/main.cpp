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
	std::cout << *f2;
	std::cout << "Lets execute this form a couple of times" << std::endl;
	b.signForm(*f2);
	b.executeForm(*f2);
	b.executeForm(*f2);
	b.executeForm(*f2);
	b.executeForm(*f2);
	b.executeForm(*f2);
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
	b.executeForm(*f3);
	delete f3;
	std::cout << "========== ==========" << std::endl;
	std::cout << "Now lets see some error handling" << std::endl;
	std::cout << "========== ==========" << std::endl;
	std::cout << "Executing a not signed form: " << std::endl;
	PresidentialPardonForm* ppf = new PresidentialPardonForm("eHan");
	if (!ppf)
		return 4;
	b.executeForm(*ppf);
	delete ppf;
	std::cout << "========== ==========" << std::endl;
	std::cout << "Not having enough grade to execute, but enough to sign" << std::endl;
	std::cout << "========== ==========" << std::endl;
	Bureaucrat b2("juan", 140);
	ShrubberyCreationForm* scf = new ShrubberyCreationForm("SCF");
	if (!scf)
		return 1;
	b2.signForm(*scf);
	b2.executeForm(*scf);
	delete scf;
}
