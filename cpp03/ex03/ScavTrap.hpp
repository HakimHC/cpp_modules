#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include "ClapTrap.hpp"
#include <string>

class ScavTrap: public ClapTrap {
	public:
		ScavTrap();
		ScavTrap(std::string);
		ScavTrap(ScavTrap& other);
		ScavTrap& operator=(ScavTrap& rhs);
		~ScavTrap();
		void guardGate();
		void attack(const std::string& target);
};

#endif
