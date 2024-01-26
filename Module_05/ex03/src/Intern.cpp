/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:48:12 by nmota-bu          #+#    #+#             */
/*   Updated: 2024/01/26 13:55:57 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Colors_ft.hpp"
#include <map>

Intern::Intern()
{
	std::cout << BURO << "[Intern]" << GREEN << " - Constructor without parameter" << RESET << std::endl;
}

Intern::Intern(const Intern &tmp)
{
	std::cout << BURO << "[Intern]" << CYAN << " - Copy constructor" << RESET << std::endl;
	*this = tmp;
}

Intern::~Intern() { std::cout << BURO << "[Intern]" << RED << " - Destructor" << RESET << std::endl; }

Intern &Intern::operator=(const Intern &tmp)
{
	std::cout << BURO << "[Intern]" << YELLOW << " - Assignation operator" << RESET << std::endl;
	if (this != &tmp)
	{
		;
	}
	return *this;
}

AForm *Intern::createPresidentialForm(std::string target) { return new PresidentialPardonForm(target); }
AForm *Intern::createRobotomyForm(std::string target) { return new RobotomyRequestForm(target); }
AForm *Intern::createShrubberyForm(std::string target) { return new ShrubberyCreationForm(target); }

const char *Intern::NotFoundException::what() const throw() { return ERROR "[ Exception ] not found on the map" RESET; }

AForm *Intern::makeForm(std::string formName, std::string target)
{

	std::map<std::string, AForm *(*)(std::string)> formMap;

	formMap["presidential"] = &createPresidentialForm;
	formMap["robotomy"] = &createRobotomyForm;
	formMap["shrubbery"] = &createShrubberyForm;

	std::map<std::string, AForm *(*)(std::string)>::iterator it = formMap.find(formName);

	if (it != formMap.end())
	{
		std::cout << formName << " es " << it->second << std::endl;
		return (it->second)(target);
	}
	else
		throw NotFound;

	return nullptr;
}
