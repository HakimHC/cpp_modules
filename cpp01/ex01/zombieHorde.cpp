#include <iostream>
#include <cstddef>

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	if (N < 0) {
		std::cout << "invalid horde num" << std::endl;
		return NULL;
	}
	Zombie* zombies = new Zombie[N];

	if (!zombies)
		return NULL;
	for (int i = 0; i < N; i++)
		zombies[i].set_name(name);
	return zombies;
}

void kill_them_all(Zombie *z)
{
	delete[] z;
}
