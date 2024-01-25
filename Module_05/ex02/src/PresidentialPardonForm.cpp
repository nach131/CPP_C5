/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:10:59 by nmota-bu          #+#    #+#             */
/*   Updated: 2024/01/25 21:23:45 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Colors_ft.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string name) : AForm(name, 25, 5) { std::cout << PRE << "[Presidential]" << GREEN << " - Constructor" << RESET << std::endl; }

PresidentialPardonForm::~PresidentialPardonForm() { std::cout << PRE << "[Presidential]" << RED << " - Destructor" << RESET << std::endl; }

void PresidentialPardonForm::execute(Bureaucrat const &bure) const
{
	AForm::execute(bure);
	std::cout << bure.getName() << " has been pardonned by Zafod Beeblebrox" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &tmp)
{
	std::cout << PRE << "[Presidential]" << YELLOW << " - Assignation operator" << RESET << std::endl;

	if (this != &tmp)
		AForm::operator=(tmp);
	return *this;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &tmp) : AForm(tmp)
{
	std::cout << PRE << "[Presidential]" << CYAN << " - Copy constructor" << RESET << std::endl;
}
