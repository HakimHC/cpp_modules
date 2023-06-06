#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <string>
# include <iostream>

class ClapTrap {

	private:
		std::string name;
		int hp;
		int ep;
		int ad;
	public:
		ClapTrap(std::string);
		ClapTrap(ClapTrap& other);
		ClapTrap& operator=(ClapTrap& rhs);
		~ClapTrap();

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		int get_ep();
};

#endif
