#include <exception>
#include <iostream>
#include <cstdlib>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void) {
	srand(time(NULL) - rand());
	int r = rand() % 3;

	switch (r) {
		case 0:
			return new A;
		case 1:
			return new B;
		case 2:
			return new C;
	}
	return NULL;
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A" << std::endl;
	if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B" << std::endl;
	if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C" << std::endl;
}

void identify(Base& p) {
	try {
		A& a = dynamic_cast<A&>(p);
		(void) a;
		std::cout << "A" << std::endl;
	}
	catch (std::exception&) {
		/* Nop */
	}
	try {
		B& a = dynamic_cast<B&>(p);
		(void) a;
		std::cout << "B" << std::endl;
	}
	catch (std::exception&) {
		/* Nop */
	}
	try {
		C& a = dynamic_cast<C&>(p);
		(void) a;
		std::cout << "C" << std::endl;
	}
	catch (std::exception&) {
		/* Nop */
	}
}

int main() {

	Base* a = new A;
	Base* b = new B;
	Base* c = new C;

	std::cout << "ptr | ref" << std::endl;

	identify(a);
	std::cout << "\t";
	identify(*a);
	std::cout << std::endl;
	identify(b);
	std::cout << "\t";
	identify(*b);
	std::cout << std::endl;
	identify(c);
	std::cout << "\t";
	identify(*c);
	std::cout << std::endl;

	std::cout << "Lets test generate()" << std::endl;
	Base* g = generate();
	Base* gg = generate();
	Base* ggg = generate();

	identify(g);
	identify(gg);
	identify(ggg);

	delete a;
	delete b;
	delete c;
	delete g;
	delete gg;
	delete ggg;

	return 0;
}
