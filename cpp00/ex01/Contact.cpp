#include "Contact.hpp"

std::string Contact::get_fn(void) {
	return this->fn;
}

std::string Contact::get_ln(void) {
	return this->ln;
}

std::string Contact::get_nn(void) {
	return this->nn;
}

std::string Contact::get_pn(void) {
	return this->pn;
}

std::string Contact::get_ds(void) {
	return this->ds;
}

void	Contact::set_fn(std::string s) {
	this->fn = s;
}

void	Contact::set_ln(std::string s) {
	this->ln = s;
}

void	Contact::set_nn(std::string s) {
	this->nn = s;
}

void	Contact::set_pn(std::string s) {
	this->pn = s;
}

void	Contact::set_ds(std::string s) {
	this->ds = s;
}

void	Contact::set_p(int b) {
	this->populated = b;
}

int Contact::exists() {
	return this->populated;
}
