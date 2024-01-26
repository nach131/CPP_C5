/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:32:09 by nmota-bu          #+#    #+#             */
/*   Updated: 2024/01/25 21:53:58 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Colors_ft.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string name) : AForm(name, 145, 137) { std::cout << TREE << "[Shrubbery]" << GREEN << " - Constructor" << RESET << std::endl; }

ShrubberyCreationForm::~ShrubberyCreationForm() { std::cout << TREE << "[Shrubbery]" << RED << " - Destructor" << RESET << std::endl; }

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &tmp)
{
	std::cout << TREE << "[Shrubbery]" << YELLOW << " - Assignation operator" << RESET << std::endl;

	if (this != &tmp)
		AForm::operator=(tmp);
	return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &tmp) : AForm(tmp)
{
	std::cout << TREE << "[Shrubbery]" << CYAN << " - Copy constructor" << RESET << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &bure) const
{
	AForm::execute(bure);

	std::string filename = bure.getName() + "_shrubbery";
	std::ofstream out(filename.c_str(), std::ofstream::out);
	if (!out)
	{
		std::cerr << "Error to open file" << std::endl;
		return;
	}

	out << "      .\n"
		<< "   __/ \\__\n"
		<< "   \\     /\n"
		<< "   /.'o'.\\\n"
		<< "    .o.'.\n"
		<< "   .'.'o'.\n"
		<< "  o'.o.'.o.\n"
		<< " .'.o.'.'.o.\n"
		<< " .'.o.'.'.o.\n"
		<< "   [_____]\n"
		<< "    \\___/    " << std::endl;

	out.close();
}
