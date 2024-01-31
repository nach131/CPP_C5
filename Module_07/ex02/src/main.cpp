
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
	printStringInCenter("[ Array Empty ]");
	{
		Array<std::string> One;
		Array<int> Two(4);

		std::cout << "Empty: " << One.empty() << std::endl;
		std::cout << "Empty: " << Two.empty() << std::endl;
	}
	printStringInCenter("[ Array Clear & Empty ]");
	{
		Array<std::string> str(3);
		str[0] = "42 Barcelona";
		str[1] = "42 Paris";
		str[2] = "42 Madrid";
		std::cout << "Empty: " << str.empty() << std::endl;

		str.clear();
		std::cout << "After clear empty: " << str.empty() << std::endl;
	}
	printStringInCenter("[ Array String Operator= ]");
	{
		Array<std::string> strA(3);
		Array<std::string> strB;

		strA[0] = "42 Barcelona";
		strA[1] = "42 Paris";
		strA[2] = "42 Madrid";

		strB = strA;

		for (size_t i = 0; i < strB.size(); i++)
			std::cout << strB[i] << std::endl;

		strA.clear();
		std::cout << "strA is empty: " << strA.empty() << std::endl;
	}
	printStringInCenter("[ Array = int ]");
	{
		Array<int> toma(3);

		toma[0] = 42;
		toma[1] = 4242;
		toma[2] = 424242;

		Array<int> strB(toma);

		for (size_t i = 0; i < strB.size(); i++)
			std::cout << strB[i] << std::endl;
	}
	printStringInCenter("[ Array = str ]");
	{
		Array<std::string> strA(3);

		strA[0] = "42 Barcelona";
		strA[1] = "42 Paris";
		strA[2] = "42 Madrid";

		Array<std::string> strB(strA);

		for (size_t i = 0; i < strB.size(); i++)
			std::cout << strB[i] << std::endl;
	}

	return 0;
}
