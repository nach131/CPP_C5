/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:22:20 by nmota-bu          #+#    #+#             */
/*   Updated: 2024/01/30 16:39:27 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors_ft.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "libft_p.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void)
{
	Bureaucrat Bure("Goku", 70);
	Intern One;

	printStringInCenter("[ Presidential OK ]");
	{
		try
		{

			AForm *form1 = One.makeForm("presidential", "pres_One");

			if (form1 != nullptr)
			{
				std::cout << "Form " << form1->getName() << " created" << std::endl;
				std::cout << *form1 << std::endl;
				delete form1;
			}
			else
			{
				std::cout << "No se pudo crear el formulario 'presidential'." << std::endl;
			}
		}
		catch (std::exception &e)
		{
			std::cout << "No se pudo crear el formulario 'pres_One': " << e.what() << std::endl;
		}
	}
	printStringInCenter("[ robotomy OK and signed can't exe ]");
	{
		try
		{
			AForm *form1 = One.makeForm("robotomy", "Robot_One");

			if (form1 != nullptr)
			{
				std::cout << "Form " << form1->getName() << " created" << std::endl;
				Bure.signForm(*form1);
				Bure.executeForm(*form1);
				delete form1;
			}
			else
			{
				std::cout << "No se pudo crear el formulario 'presidential'." << std::endl;
			}
		}
		catch (std::exception &e)
		{
			std::cout << "No se pudo crear el formulario 'Robot_One': " << e.what() << std::endl;
		}
	}
	printStringInCenter("[ Shrubbery signed exe OK ]");
	{
		try
		{
			AForm *form1 = One.makeForm("shrubbery", "Tree_One");

			if (form1 != nullptr)
			{
				std::cout << "Form " << form1->getName() << " created" << std::endl;
				Bure.signForm(*form1);
				Bure.executeForm(*form1);
				delete form1;
			}
			else
			{
				std::cout << "No se pudo crear el formulario 'shrubbery'." << std::endl;
			}
		}
		catch (std::exception &e)
		{
			std::cout << "No se pudo crear el formulario 'shrubbery': " << e.what() << std::endl;
		}
	}
	printStringInCenter("[ tomate error ]");
	{
		try
		{
			AForm *form2 = One.makeForm("tomate", "tomate");
			if (form2 != nullptr)
			{
				std::cout << "Formulario 'presidential' creado correctamente." << std::endl;
				std::cout << *form2 << std::endl;
				delete form2;
			}
		}
		catch (std::exception &e)
		{
			std::cout << "No se pudo crear el formulario 'tomate': " << e.what() << std::endl;
		}
	}
}
