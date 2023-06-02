#include <iostream>

#include "Harl.hpp"

Harl::Harl(){}
Harl::~Harl(){}

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "info log cheese" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "warning log bacon" << std::endl;
}

void Harl::error(void)
{
	std::cout << "error hamburger" << std::endl;
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
