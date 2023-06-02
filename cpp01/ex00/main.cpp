#include "Zombie.hpp"
#include <iostream>

int	main(void)
{
	randomChump("static_zombie");
	Zombie* d = newZombie("dynamic_zombie");

	d->announce();
	delete d;
}
