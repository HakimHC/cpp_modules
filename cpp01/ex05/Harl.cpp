#include <iostream>

#include "Harl.hpp"

Harl::Harl(){}
Harl::~Harl(){}

void Harl::debug(void)
{
	std::cout << "DEBUG LOG" << std::endl;
}

void Harl::info(void)
{
	std::cout << "INFO LOG" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "WARNING LOG" << std::endl;
}

void Harl::error(void)
{
	std::cout << "ERROR LOG" << std::endl;
}

void Harl::complain(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	void (Harl::*ptr[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i = 0; i < 4; i++) {
		if (levels[i] == level)
			(this->*ptr[i])();
	}
}
