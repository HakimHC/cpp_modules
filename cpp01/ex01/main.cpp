#include "Zombie.hpp"
#include <iostream>

int	main(void)
{
	int i;
	int n = 5;
	std::string name = "first_horde";

	std::cout << "Let's create the first horde, containing " << n << " zombies" <<std::endl;

	Zombie *z = zombieHorde(n, name);
	if (!z)
		return 1;
	for (i = 0; i < n; i++)
		z[i].announce();

	kill_them_all(z);

	n = 0;
	name = "second_horde";
	std::cout << "The second horde is a bit smaller, containing " << n << " zombies" <<std::endl;
	z = zombieHorde(n, name);
	if (!z)
		return 1;

	kill_them_all(z);


	n = -15;
	name = "klk manin";
	std::cout << "now lets go crazy, horde: " << n << " zombies" <<std::endl;

	z = zombieHorde(n, name);
	if (!z)
		return 1;
}
