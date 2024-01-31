
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
#include "Colors_ft.hpp"
#include "libft_p.hpp"
#include "easyfind.hpp"
#include <vector>
#include <list>
#include <map>
#include <set>
// #include <algorithm>

int main()
{

	int arr[] = {1, 2, 3, 4, 5};

	printStringInCenter("[ Vector ]");
	{
		std::vector<int> numbers(arr, arr + sizeof(arr) / sizeof(arr[0]));

		try
		{
			easyfind(numbers, 3);
			easyfind(numbers, 5);
			easyfind(numbers, 6);
		}
		catch (const std::string &ex)
		{
			std::cout << RED << "Exception: " << ex << RESET << std::endl;
		}
	}
	printStringInCenter("[ List ]");
	{
		std::list<int> numbers(arr, arr + sizeof(arr) / sizeof(arr[0]));

		try
		{
			easyfind(numbers, 3);
			easyfind(numbers, 5);
			easyfind(numbers, 6);
		}
		catch (const std::string &ex)
		{
			std::cout << RED << "Exception: " << ex << RESET << std::endl;
		}
	}
	printStringInCenter("[ Set ]");
	{
		std::set<int> numbers(arr, arr + sizeof(arr) / sizeof(arr[0]));

		try
		{
			easyfind(numbers, 3);
			easyfind(numbers, 5);
			easyfind(numbers, 6);
		}
		catch (const std::string &ex)
		{
			std::cout << RED << "Exception: " << ex << RESET << std::endl;
		}
	}
	printStringInCenter("[ Map ]");
	{
		std::map<int, int> numbers;

		for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
			numbers[i + 1] = i;

		try
		{
			easyfindMap(numbers, 3);
			easyfindMap(numbers, 5);
			easyfindMap(numbers, 6);
		}
		catch (const std::string &ex)
		{
			std::cout << RED << "Exception: " << ex << RESET << std::endl;
		}
	}
	return 0;
}
