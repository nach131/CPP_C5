/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:22:20 by nmota-bu          #+#    #+#             */
/*   Updated: 2024/01/26 10:12:03 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors_ft.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "libft_p.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	printStringInCenter("[ Bureaucrat Low grade Presi]");
	{
		try
		{
			Bureaucrat a("Goku", 100);
			PresidentialPardonForm Pre("Presidential");
			Pre.execute(a);
			std::cout << Pre << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	printStringInCenter("[ Form Prefi Not Signed ]");
	{
		try
		{
			Bureaucrat a("Goku", 1);
			PresidentialPardonForm Pre("Presidential");
			std::cout << Pre << std::endl;
			Pre.execute(a);
			std::cout << Pre << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	printStringInCenter("[ OK Presi]");
	{
		try
		{
			Bureaucrat a("Goku", 1);
			PresidentialPardonForm Pre("Presidential");
			std::cout << Pre << std::endl;
			Pre.beSigned(a);
			Pre.execute(a);
			std::cout << Pre << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	printStringInCenter("[ OK Robot]");
	{
		try
		{
			Bureaucrat a("Koji Kabuto", 1);
			RobotomyRequestForm Robot("Mazinger Z");
			std::cout << Robot << std::endl;
			Robot.beSigned(a);
			Robot.execute(a);
			std::cout << Robot << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	printStringInCenter("[ Tree]");
	{
		try
		{
			Bureaucrat a("Salicaceas", 1);
			ShrubberyCreationForm Tree("Tree");
			Tree.beSigned(a);
			Tree.execute(a);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	printStringInCenter("[ Execute whit Bureaucrat ]");
	{
		Bureaucrat a("Vegetta", 1); // Subir par no cumplir
		PresidentialPardonForm Pre("Presidential");
		Pre.beSigned(a); // para no cumplir
		a.executeForm(Pre);
		std::cout << Pre << std::endl;
	}
	printStringInCenter("[ Constructor Copy ]");
	{
		try
		{
			Bureaucrat a("Dirty Harry", 1);
			PresidentialPardonForm RobotA("Ronal Regan");
			PresidentialPardonForm RobotB(RobotA);

			std::cout << RobotA << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}
