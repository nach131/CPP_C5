
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

	printStringInCenter("[ 6, 3, 17, 9, 11 ]");

	{
		Span One = Span(5);
		One.addNumber(5);
		One.addNumber(3);
		One.addNumber(17);
		One.addNumber(9);
		One.addNumber(11);
		std::cout << "Shortest Span: " << One.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << One.longestSpan() << std::endl;
		One.printSort();
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
			// One.printValues();
		}
		catch (std::exception &e)
		{
			std::cerr << RED "[ Exception ] " << e.what() << RESET << std::endl;
		}
	}

	// printStringInCenter("[  ]");
	// {
	// 	try
	// 	{
	// 		Span One(10);

	// 		for (size_t i = 0; i < One.size; i++)
	// 			One.addNumber(i * 1.4);
	// 		std::cout << "Shortest Span: " << One.shortestSpan() << std::endl;
	// 	}
	// 	catch (std::exception &e)
	// 	{
	// 		std::cerr << RED "[ Exception ] " << e.what() << RESET << std::endl;
	// 	}
	// }

	return 0;
}
