
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

#include <iostream>
#include "ColorsFt.hpp"
#include "libftPlus.hpp"
#include "Array.hpp"

int main()
{
	// {
	// 	Array<int> integer;
	// 	integer[0] = new
	// }
	printStringInCenter("[ Int ]");
	{
		Array<int> toma(10);
		for (size_t i = 0; i < toma.size(); i++)
		{
			toma[i] = i + 10;
			std::cout << toma[i] << std::endl;
		}

		std::cout << "size: " << toma.size() << std::endl;
	}
	printStringInCenter("[ String ]");
	{
		Array<std::string> strings;
		Array<std::string> str(3);
		str[0] = "42 Barcelona";
		str[1] = "42 Paris";
		str[2] = "42 Madrid";

		for (size_t i = 0; i < str.size(); i++)
			std::cout << str[i] << std::endl;
	}
	printStringInCenter("[ String out of bounds ]");
	{
		Array<std::string> str(3);
		try
		{
			str[3] = "42 Madrid";
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	printStringInCenter("[ Array Empty]");
	{
		Array<std::string> One;
		Array<int> Two(4);

		std::cout << "Empty: " << One.empty() << std::endl;
		std::cout << "Empty: " << Two.empty() << std::endl;
	}
	printStringInCenter("[ Array Empty]");
	{
		Array<std::string> str(3);
		str[0] = "42 Barcelona";
		str[1] = "42 Paris";
		str[2] = "42 Madrid";
		std::cout << "Empty: " << str.empty() << std::endl;

		str.clear();
		std::cout << "After clear empty: " << str.empty() << std::endl;
	}
	// printStringInCenter("[ Array int asignacion]");
	// {

	// Array<int> One[] = {32, 43, 32};

	// Array<int> One[] = {Array<int>(32), Array<int>(43), Array<int>(32)};
	// std::cout << One->size() << std::endl;

	// for (size_t i = 0; i < One->size(); i++)
	// {
	// 	for (size_t j = 0; j < One[i].size(); j++)
	// 	{
	// 		std::cout << One[i][j] << ", ";
	// 	}
	// }
	// }
	return 0;
}
