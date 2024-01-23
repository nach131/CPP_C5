/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:22:20 by nmota-bu          #+#    #+#             */
/*   Updated: 2024/01/23 16:34:55 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Colors_ft.hpp"

int main(void)
{
	{
		std::cout << "\t\t" << MAIN << "[ Exception ]" << RESET << std::endl;
		try
		{
			Bureaucrat one("Goku", -12);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			Bureaucrat Two("Vegeta", 152);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << "\n\t\t" << MAIN << "[ Mandatory ]" << RESET << std::endl;
		try
		{
			Bureaucrat One("Bulma", 12);
			std::cout << One << std::endl;
			One.up(32);
			One.down(2);
			std::cout << One << std::endl;
			One.down(200);
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << "\n\t\t" << MAIN << "[ Operator = ]" << RESET << std::endl;
		Bureaucrat one("Goku", 12);
		Bureaucrat two;

		two = one;

		std::cout << one << std::endl;
		std::cout << two << std::endl;
	}

	return 0;
}
