/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim </var/spool/mail/hakim>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 05:00:57 by hakim             #+#    #+#             */
/*   Updated: 2023/06/12 21:08:35 by hakahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

// CANONICAL MEMBER FUNCTIONS

// ===================================================================================

ShrubberyCreationForm::ShrubberyCreationForm()
	:AForm("SCFform", 145, 137), _target("home")
{std::cout << "ShrubberyCreationForm default constructor called" << std::endl;}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	:AForm("SCFform", 145, 137), _target(target)
{std::cout << "ShrubberyCreationForm target constructor called" << std::endl;}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm& other)
	:AForm(other.getName(), other.getRGradeSign(), other.getRGradeExec())
{std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm& rhs) {
	if (this != &rhs) {
		this->setSign(rhs.isSigned());
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{std::cout << "ShrubberyCreationForm destructor called" << std::endl;}

// ===================================================================================

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (!this->isSigned())
		throw FormNotSignedException();
	if (!this->isExecutable(executor.getGrade()))
		throw GradeTooLowException();

	std::ofstream outfile;
	outfile.open(std::string(this->_target + "_shrubbery").c_str());
	if (!outfile.is_open()) {
		std::cerr << "fatal: can't open outfile" << std::endl;
		return ;
	}
	outfile << "| a s c i i  t r e e s |" << std::endl;
	outfile.close();;
}
