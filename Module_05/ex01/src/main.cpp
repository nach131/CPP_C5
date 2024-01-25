/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:22:20 by nmota-bu          #+#    #+#             */
/*   Updated: 2024/01/25 11:13:23 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors_ft.hpp"
#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "libft_p.hpp"

int main(void)
{
	{
		printStringInCenter("[ Exception ]");

		try
		{
			Form One("Example Form", -12, 11);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			Form Two("Example Form", 70, 211);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		printStringInCenter("[ Signed Form OK ]");

		try
		{
			Form form("Model 130", 10, 10);
			Bureaucrat One("One", 2);
			Bureaucrat Two("Two", 110);

			std::cout << form << std::endl;

			One.signForm(form);
			std::cout << form << std::endl;
			Two.signForm(form);
		}
		catch (const std::exception &e)
		{
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
	}
	{
		printStringInCenter("[ Signed Form Error ]");

		try
		{
			Form form("Model 130", 10, 10);
			Bureaucrat Two("Two", 110);

			std::cout << form << std::endl;

			Two.signForm(form);
		}
		catch (const std::exception &e)
		{
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
	}
	{
		printStringInCenter("[ Operator = ]");

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
