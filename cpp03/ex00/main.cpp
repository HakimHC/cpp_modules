#include "ClapTrap.hpp"

int main() {
	ClapTrap c("carlos");

	c.attack("arduino");
	std::cout << "Current energy points: " << c.get_ep() << std::endl;
	for (int i = 0; i < 10; i++) {
		c.takeDamage(1);
	}
	std::cout << "From here on, carlos wont be able to do anything" << std::endl;
	c.beRepaired(45);
	c.beRepaired(10000);

	std::cout << "Well, it certainly sucks that carlos died, let's see what will happen to...." << std::endl;
	ClapTrap j("juan");

	for (int i = 0; i < 10; i++) {
		std::cout << "Current energy points: " << j.get_ep() << std::endl;
		j.attack("ajskdja");
		j.beRepaired(5);
	}
}
