#include <cstdlib>
#include <exception>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main() {

	Intern i;

	AForm* f = i.makeForm("robotomy request", "carlos");
	std::cout << *f;
	AForm* f2 = i.makeForm("shrubbery creation", "carlos");
	std::cout << *f2;
	AForm* f3 = i.makeForm("presidential pardon", "carlos");
	std::cout << *f3;

	delete f;
	delete f2;
	delete f3;

	std::cout << "Now lets create invalid stuff" << std::endl;
	AForm* f4 = i.makeForm("juan", "carlos");
	(void) f4;
}
