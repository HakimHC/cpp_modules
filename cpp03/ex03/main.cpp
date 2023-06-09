#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
	DiamondTrap d("juan");

	d.whoAmI();

	d.attack("hello");

}
