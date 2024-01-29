
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
#include "iter.hpp"

int main()
{
	printStringInCenter("[ Arr Int ]");
	{
		int arr[] = {1, 2, 3, 4, 5};
		my::iter(arr, 5, my::printItem<int>);
	}
	printStringInCenter("[ Arr Double ]");
	{
		double doubleArr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
		my::iter(doubleArr, 5, my::printItem<double>);
	}
	printStringInCenter("[ Arr Boolean ]");
	{
		bool boolArr[] = {true, false, true, false, true};
		my::iter(boolArr, 5, my::printItem<bool>);
	}
	printStringInCenter("[ Arr Char ]");
	{
		char arr[] = {33, 34, 35, 36, 37};
		my::iter(arr, 5, my::printItem<char>);
	}
	printStringInCenter("[ Arr String ]");
	{
		std::string arr[] = {"RED", "BLUE", "CYAN", "MAGENTA", "YELLOW"};
		my::iter(arr, 5, my::printItem<std::string>);
	}
	printStringInCenter("[ Arr ptr ]");
	{
		int *ptrArr[] = {new int(1), new int(2), new int(3)};
		my::iter(ptrArr, 3, my::printItem<int *>);

		for (size_t i = 0; i < 3; i++)
			delete ptrArr[i];
	}
	printStringInCenter("[ Arr Structura & Operator<< ]");
	{
		Person personArr[] = {{"Goku", 10000}, {"Vegeta", 9000}, {"Piccolo", 8000}};
		my::iter(personArr, 3, my::printItem<Person>);
	}

	return 0;
}
