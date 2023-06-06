#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {

	ScavTrap a("1");
	ScavTrap b("2");

	a.attack("carlos");
	a.guardGate();
	b.takeDamage(1000000);
	b.guardGate();
}
