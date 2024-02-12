
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
#include "BitcoinExchange.hpp"
#include <limits.h>

bool isValidDate(const std::string &dateString)
{
	std::istringstream ss(dateString);
	std::tm t = {};
	ss >> std::get_time(&t, "%Y-%m-%d");
	return !ss.fail();
}

bool ctrFile(std::string date, std::string value)
{
	if (!isValidDate(date) || value.empty())
	{
		std::cerr << ERROR << "Error: bad input => " << date << RESET << std::endl;
		return true;
	}

	return false;
}

bool ctrValue(float num)
{
	if (num <= 0)
	{
		std::cerr << ERROR << "Error: not a positive number." << RESET << std::endl;
		return true;
	}
	else if (num >= INT_MAX)
	{
		std::cerr << ERROR << "Error: too large a number." << RESET << std::endl;
		return true;
	}
	return false;
}

int main(int n, char **str)
{

	if (n != 2)
	{
		std::cerr << ERROR << "Error: could not open file." << RESET << std::endl;
		return EXIT_FAILURE;
	}

	std::ifstream file(str[1]);
	if (!file)
	{
		std::cerr << ERROR << "Error opening file " << str[1] << RESET << std::endl;
		exit(1);
	}

	BitcoinExchange exchange;
	std::string line;
	bool flag;
	bool isFirstLine = true;

	while (std::getline(file, line))
	{
		if (isFirstLine)
		{
			isFirstLine = false;
			continue;
		}
		std::istringstream iss(line);
		std::string date, value;
		std::getline(iss, date, '|');
		std::getline(iss, value, '|');

		flag = ctrFile(date, value);

		std::stringstream ss(value);
		float floatValue;
		ss >> floatValue;

		flag = ctrValue(floatValue);

		if (!flag)
			exchange.change(date, floatValue);
	}
	file.close();

	return EXIT_SUCCESS;
}
