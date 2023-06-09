#include <exception>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	Bureaucrat b("hakim", 3);
	PresidentialPardonForm* f = new PresidentialPardonForm("fos");

	b.signForm(*f);
	b.executeForm(*f);
}
