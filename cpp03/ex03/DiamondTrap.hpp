#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H

# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap {

	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap& other);
		DiamondTrap& operator=(DiamondTrap& rhs);
		~DiamondTrap();

		std::string getHP();
		std::string getAD();
		void whoAmI();
		void attack(std::string);
	private:
		std::string name;
};

#endif
