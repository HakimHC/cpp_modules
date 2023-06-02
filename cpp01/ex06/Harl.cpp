/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakahmed <hakahmed@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 20:37:58 by hakahmed          #+#    #+#             */
/*   Updated: 2023/05/25 20:56:24 by hakahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Harl.hpp"

Harl::Harl(){}
Harl::~Harl(){}

void Harl::set_level(level lvl)
{
	this->lvl = lvl;
}

level Harl::get_level()
{
	return this->lvl;
}

void Harl::debug(void)
{
	std::cout << "debug log cangrejo" << std::endl;
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
	enum level lvl = convert_str(level);

	if (lvl >= this->lvl) {
		switch(lvl) {
			case DEBUG:
				this->debug();
				break;
			case INFO:
				this->info();
				break;
			case WARNING:
				this->warning();
				break;
			case ERROR:
				this->error();
				break;
			default:
				break;
		}
	}
}
