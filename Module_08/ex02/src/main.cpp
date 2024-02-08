
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:22:20 by nmota-bu          #+#    #+#             */
/*   Updated: 2024/01/28 12:20:40 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ColorsFt.hpp"
#include "libftPlus.hpp"
#include "Span.hpp"

int main()
{
	// printStringInCenter("[ Exeption add more than capacity ]");
	// {
	// 	try
	// 	{
	// 		Span Two(1);
	// 		Two.addNumber(12);
	// 		Two.addNumber(112);
	// 	}
	// 	catch (std::exception &e)
	// 	{
	// 		std::cerr << RED "[ Exception ] " << e.what() << RESET << std::endl;
	// 	}
	// }
	printStringInCenter("[ Vector 0 Error: Shortest ]");
	{
		try
		{
			Span One(0);
			std::cout << "Shortest Span: " << One.shortestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << RED "[ Exception ] " << e.what() << RESET << std::endl;
		}
	}
	printStringInCenter("[ Vector 1 Error: Shortest ]");
	{
		try
		{
			Span One(1);
			One.addNumber(4242);
			std::cout << One.shortestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << RED "[ Exception ] " << e.what() << RESET << std::endl;
		}
	}

	printStringInCenter("[ Vector 1 Error: Longest ]");
	{
		try
		{
			Span One(1);
			One.addNumber(4242);
			std::cout << One.longestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << RED "[ Exception ] " << e.what() << RESET << std::endl;
		}
	}

	printStringInCenter("[ Vector 20 Random with repeated num ? ]");
	{
		try
		{
			Span One(20);
			std::cout << "getSize: " << One.getSize() << std::endl;
			std::cout << "getCapacity: " << One.getCapacity() << std::endl;
			for (size_t i = 0; i < One.getCapacity(); i++)
				One.addNumber(getRandomNumber(0, 200));

			std::cout << "getSize After for: " << One.getSize() << std::endl;
			std::cout << "Shortest Span: " << One.shortestSpan() << std::endl;
			std::cout << "Longest Span: " << One.longestSpan() << std::endl;
			One.printValues();
			One.printSort();
		}
		catch (std::exception &e)
		{
			std::cerr << RED "[ Exception ] " << e.what() << RESET << std::endl;
		}
	}

	printStringInCenter("[ Vector 100 +42]");
	{
		try
		{
			Span One(100);
			for (size_t i = 0; i < 100; i++)
				One.addNumber(i * 1.33);

			std::cout << "Shortest Span: " << One.shortestSpan() << std::endl;
			std::cout << "Longest Span: " << One.longestSpan() << std::endl;

			One.printValues();
		}
		catch (std::exception &e)
		{
			std::cerr << RED "[ Exception ] " << e.what() << RESET << std::endl;
		}
	}

	printStringInCenter("[ Vector 1000 Random]");
	{
		try
		{
			Span One(1000);
			for (size_t i = 0; i < 1000; i++)
				One.addNumber(getRandomNumber(INT_MIN, INT_MAX));

			std::cout << "Shortest Span: " << One.shortestSpan() << std::endl;
			std::cout << "Longest Span: " << One.longestSpan() << std::endl;
			// One.printSort();
		}
		catch (std::exception &e)
		{
			std::cerr << RED "[ Exception ] " << e.what() << RESET << std::endl;
		}
	}

	printStringInCenter("[ Assignation & Operator= ]");
	{
		try
		{
			Span One(10);

			for (size_t i = 0; i < One.getCapacity(); i++)
				One.addNumber(getRandomNumber(0, 30));

			Span Two(One);
			Two.printValues();
		}
		catch (std::exception &e)
		{
			std::cerr << RED "[ Exception ] " << e.what() << RESET << std::endl;
		}
	}

	printStringInCenter("[ Subject 6, 3, 17, 9, 11 ]");
	{
		try
		{
			Span sp = Span(5);
			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);
			std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
			std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << RED "[ Exception ] " << e.what() << RESET << std::endl;
		}
	}

	return 0;
}
