#include <exception>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {

	ShrubberyCreationForm* s = new ShrubberyCreationForm("puta");
	Bureaucrat b("janklin", 4);
	b.signForm(*s);
	s->execute(b);
}
