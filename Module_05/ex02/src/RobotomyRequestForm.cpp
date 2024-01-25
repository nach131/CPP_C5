/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:32:09 by nmota-bu          #+#    #+#             */
/*   Updated: 2024/01/25 21:40:36 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Colors_ft.hpp"
#include <vector>
#include <unistd.h>

RobotomyRequestForm::RobotomyRequestForm(std::string name) : AForm(name, 72, 45) { std::cout << ROBOT << "[Robot]" << GREEN << " - Constructor" << RESET << std::endl; }

RobotomyRequestForm::~RobotomyRequestForm() { std::cout << ROBOT << "[Robot]" << RED << " - Destructor" << RESET << std::endl; }

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &tmp)
{
	std::cout << ROBOT << "[Robot]" << YELLOW << " - Assignation operator" << RESET << std::endl;

	if (this != &tmp)
		AForm::operator=(tmp);
	return *this;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &tmp) : AForm(tmp)
{
	std::cout << ROBOT << "[Robot]" << CYAN << " - Copy constructor" << RESET << std::endl;
}

void imprimirConPausa(const std::vector<std::string> &palabras)
{
	for (std::vector<std::string>::const_iterator it = palabras.begin(); it != palabras.end(); ++it)
	{
		std::cout << ORANGE << *it << RESET << std::endl;
		std::cout.flush();
		sleep(1);
	}
}

void initVector(std::vector<std::string> *toma)
{
	toma->push_back("*creak*");
	toma->push_back("!BANG!");
	toma->push_back("Hahaha!");
	toma->push_back("~sigh~");
	toma->push_back("~~~~~~");
	toma->push_back("!!!");
	toma->push_back("THUD THUD THUD");
	toma->push_back("BZZZZZZZ");
	toma->push_back("drip... drip...");
}

void RobotomyRequestForm::execute(Bureaucrat const &bure) const
{
	AForm::execute(bure);
	std::vector<std::string> ruidos;
	initVector(&ruidos);
	imprimirConPausa(ruidos);
	if (rand() % 2 == 0)
		std::cout << GREEN << this->getName() << " has been robotomized successfully " << RESET << std::endl;
	else
		std::cout << RED << this->getName() << " has failed" << RESET << std::endl;
}
