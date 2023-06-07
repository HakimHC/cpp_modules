#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H

# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap {

	public:
		DiamondTrap();
		DiamondTrap(std::string name);


	private:
		std::string name;
		FragTrap::hp;
		ScavTrap::ep;

};

#endif
