#ifndef FRAGTRAP_H
# define FRAGTRAP_H

# include "ClapTrap.hpp"

class FragTrap: public ClapTrap {
	
	public:
		FragTrap();
		FragTrap(std::string& name);
		FragTrap(FragTrap& other);
		FragTrap& operator=(FragTrap& rhs);
		~FragTrap();

		void highFiveGuys();
		void attack(const std::string& target);
};

#endif
