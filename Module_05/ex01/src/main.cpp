/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:22:20 by nmota-bu          #+#    #+#             */
/*   Updated: 2024/01/24 13:05:22 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors_ft.hpp"
#include "Form.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
	// {
	// 	std::cout << "\t\t" << MAIN << "[ Exception ]" << RESET << std::endl;
	// 	try
	// 	{
	// 		Bureaucrat one("Goku", -12);
	// 	}
	// 	catch (std::exception &e)
	// 	{
	// 		std::cerr << e.what() << std::endl;
	// 	}
	// 	try
	// 	{
	// 		Bureaucrat Two("Vegeta", 152);
	// 	}
	// 	catch (std::exception &e)
	// 	{
	// 		std::cerr << e.what() << std::endl;
	// 	}
	// }
	// {
	// 	std::cout << "\n\t\t" << MAIN << "[ Mandatory ]" << RESET << std::endl;
	// 	try
	// 	{
	// 		Form form("Example Form", 75);
	// 		std::cout << "Name: " << form.getName() << ", Grade: " << form.getGrade() << std::endl;

	// 		form.upSig(5);
	// 		std::cout << "After raising the grade: " << form.getGrade() << std::endl;

	// 		form.downSig(10);
	// 		std::cout << "After lowering the grade: " << form.getGrade() << std::endl;

	// 		// Uncomment the following line to trigger an exception
	// 		// form.down(200);
	// 	}
	// 	catch (const std::exception &e)
	// 	{
	// 		std::cerr << "Exception caught: " << e.what() << std::endl;
	// 	}
	// }
	{
		std::cout << "\n\t\t" << MAIN << "[ Operator = ]" << RESET << std::endl;

		try
		{
			Form *myForm = new Form("DynamicForm", 90, 120);

			std::cout << "Dynamic Form - Name: " << myForm->getName() << ", Grade: " << myForm->getGradeSig() << std::endl;

			Form anotherForm("AnotherForm", 80, 10);
			*myForm = anotherForm;
			std::cout << "After assignment - Name: " << myForm->getName() << ", Grade: " << myForm->getGradeSig() << std::endl;

			std::cout << *myForm << std::endl;

			delete myForm;
		}
		catch (const std::exception &e)
		{
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
	}
}
