#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <string>
# include <iostream>

class ClapTrap {

	protected:
		std::string name;
		unsigned int hp;
		unsigned int ep;
		unsigned int ad;
	public:
		ClapTrap();
		ClapTrap(std::string);
		ClapTrap(ClapTrap& other);
		ClapTrap& operator=(ClapTrap& rhs);
		virtual ~ClapTrap();

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		int get_ep();
};

#endif
