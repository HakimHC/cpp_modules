#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {

	ClapTrap a("bongo");

	a.attack("carlos");
	a.beRepaired(1000);
	a.takeDamage(2000);
	a.attack("carlos");

	ScavTrap b("1");

	b.attack("carlos");
	b.guardGate();
	b.takeDamage(1000000);
	b.guardGate();
	b.beRepaired(19999);
	b.attack("juan");

	FragTrap f;

	f.highFiveGuys();
	f.takeDamage(1000000);
	f.highFiveGuys();
}
