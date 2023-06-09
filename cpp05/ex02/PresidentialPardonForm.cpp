/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim </var/spool/mail/hakim>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 05:00:57 by hakim             #+#    #+#             */
/*   Updated: 2023/06/09 05:18:55 by hakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

// CANONICAL MEMBER FUNCTIONS

// ===================================================================================

PresidentialPardonForm::PresidentialPardonForm()
	:AForm("PPFform", 25, 5), _target("home")
{std::cout << "PresidentialPardonForm default constructor called" << std::endl;}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	:AForm("PPFform", 25, 5), _target(target)
{std::cout << "PresidentialPardonForm target constructor called" << std::endl;}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm& other)
	:AForm(other.getName(), other.getRGradeSign(), other.getRGradeExec())
{std::cout << "PresidentialPardonForm copy constructor called" << std::endl;}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm& rhs) {
	if (this != &rhs) {
		this->setSign(rhs.isSigned());
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{std::cout << "PresidentialPardonForm destructor called" << std::endl;}

// ===================================================================================

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (!this->isSigned())
		throw FormNotSignedException();
	if (this->getRGradeExec() < executor.getGrade())
		throw GradeTooLowException();
	
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
