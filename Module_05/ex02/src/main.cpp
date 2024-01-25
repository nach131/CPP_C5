/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:22:20 by nmota-bu          #+#    #+#             */
/*   Updated: 2024/01/25 19:23:52 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors_ft.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "libft_p.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	printStringInCenter("[ Bureaucrat Low grade ]");
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
	printStringInCenter("[ Form Not Signed ]");
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
	printStringInCenter("[ OK ]");
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
	// {
	// 	printStringInCenter("[ Signed Form OK ]");

	// 	try
	// 	{
	// 		Form form("Model 130", 10, 10);
	// 		Bureaucrat One("One", 2);
	// 		Bureaucrat Two("Two", 110);

	// 		std::cout << form << std::endl;

	// 		One.signForm(form);
	// 		std::cout << form << std::endl;
	// 		Two.signForm(form);
	// 	}
	// 	catch (const std::exception &e)
	// 	{
	// 		std::cerr << "Exception caught: " << e.what() << std::endl;
	// 	}
	// }
	// {
	// 	printStringInCenter("[ Signed Form Error ]");

	// 	try
	// 	{
	// 		Form form("Model 130", 10, 10);
	// 		Bureaucrat Two("Two", 110);

	// 		std::cout << form << std::endl;

	// 		Two.signForm(form);
	// 	}
	// 	catch (const std::exception &e)
	// 	{
	// 		std::cerr << "Exception caught: " << e.what() << std::endl;
	// 	}
	// }
	// {
	// 	printStringInCenter("[ Operator = ]");

	// 	try
	// 	{
	// 		Form *myForm = new Form("DynamicForm", 90, 120);

	// 		std::cout << "Dynamic Form - Name: " << myForm->getName() << ", Grade: " << myForm->getGradeSig() << std::endl;

	// 		Form anotherForm("AnotherForm", 80, 10);
	// 		*myForm = anotherForm;
	// 		std::cout << "After assignment - Name: " << myForm->getName() << ", Grade: " << myForm->getGradeSig() << std::endl;

	// 		std::cout << *myForm << std::endl;

	// 		delete myForm;
	// 	}
	// 	catch (const std::exception &e)
	// 	{
	// 		std::cerr << "Exception caught: " << e.what() << std::endl;
	// 	}
	// }
}
