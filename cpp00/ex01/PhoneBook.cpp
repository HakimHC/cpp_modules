#include <iostream>
#include <sstream>
#include <string>

#include "PhoneBook.hpp"
#include "Contact.hpp"

int PhoneBook::cptr = 0;
Contact PhoneBook::c[8];

int PhoneBook::get_cptr() {
	return this->cptr;
}

void PhoneBook::incr_cptr() {
	this->cptr = (this->cptr == 7 ? 0 : this->cptr + 1);
}

Contact PhoneBook::get_c(int n) {
	return this->c[n];
}

void PhoneBook::set_c(int n, Contact c) {
	this->c[n] = c;
}

void PhoneBook::add_contact() {
	int n = this->cptr;
	std::string line = "";

	while (line.empty()) {
		std::cout << "First name: ";
		std::getline(std::cin, line);
		this->c[n].set_fn(line);
	}
	line = "";
	while (line.empty()) {
		std::cout << "Last name: ";
		std::getline(std::cin, line);
		this->c[n].set_ln(line);
	}
	line = "";
	while (line.empty()) {
		std::cout << "Nick name: ";
		std::getline(std::cin, line);
		this->c[n].set_nn(line);
	}
	line = "";
	while (line.empty()) {
		std::cout << "Phone number: ";
		std::getline(std::cin, line);
		this->c[n].set_pn(line);
	}
	line = "";
	while (line.empty()) {
		std::cout << "Darkest secret: ";
		std::getline(std::cin, line);
		this->c[n].set_ds(line);
	}
	this->incr_cptr();
	this->c[n].set_p(1);
	std::cout << this->get_cptr() << std::endl;
}

void PhoneBook::pfield(std::string s) {
	size_t i;
	for (i = 0; i + s.length() < 10; i++)
		std::cout << " ";
	if (i)
		std::cout << s << "|";
	else {
		for (int i = 0; i < 9; i++)
			std::cout << s.at(i);
		std::cout << ".|";
	}
}

void PhoneBook::display() {
	this->pfield("index");
	this->pfield("first name");
	this->pfield("last name");
	this->pfield("nickname");
	std::cout << std::endl;
	int i = 0;
	while (this->get_c(i).exists() != 0)
	{
		std::stringstream n;
		n << i + 1;
		this->pfield(n.str());
		this->pfield(this->c[i].get_fn());
		this->pfield(this->c[i].get_ln());
		this->pfield(this->c[i].get_nn());
		std::cout << std::endl;
		i++;
	}
	std::string line = "";
	int index;
	while (line.empty()) {
		std::cout << "Select index: ";
		std::getline(std::cin, line);
		std::stringstream ss(line);
		if (!(ss >> index) || !this->c[index - 1].exists() || index < 1) {
			std::cout << "fatal: invalid index" << std::endl;
			line = "";
		}
	}
	std::cout << "First name: " << this->c[index - 1].get_fn() << std::endl;
	std::cout << "Last name: " << this->c[index - 1].get_ln() << std::endl;
	std::cout << "Nickname: " << this->c[index - 1].get_nn() << std::endl;
	std::cout << "Phone number: " << this->c[index - 1].get_pn() << std::endl;
	std::cout << "Darkest secret: " << this->c[index - 1].get_ds() << std::endl;
}
