/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:57:43 by nmota-bu          #+#    #+#             */
/*   Updated: 2024/02/12 23:28:21 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

BitcoinExchange::BitcoinExchange()
{
	readCSV("data.csv");
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &tmp) { *this = tmp; }

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &tmp)
{
	if (this != &tmp)
		;
	return *this;
}

void BitcoinExchange::readCSV(const std::string &filename)
{
	std::ifstream file(filename);
	if (!file)
	{
		std::cerr << ERROR << "Error opening file " << filename << RESET << std::endl;
		exit(1);
	}

	std::string line;
	while (std::getline(file, line))
	{
		std::istringstream iss(line);
		std::string date, value;
		std::getline(iss, date, ',');
		std::getline(iss, value, ',');

		_data[date] = value;
	}

	file.close();
}

void BitcoinExchange::pConvert(const std::string date, float value, float num)
{
	std::cout << date << " => " << num << " = " << value * num << std::endl;
}

void BitcoinExchange::change(const std::string date, float num)
{
	std::map<std::string, std::string>::iterator it = _data.find(date);

	(void)num;
	if (it != _data.end())
		pConvert(date, atof(it->second.c_str()), num);
	else
	{
		// Buscar la fecha anterior más cercana
		it = _data.lower_bound(date);
		if (it != _data.begin())
		{
			--it;
			pConvert(date, atof(it->second.c_str()), num);
		}
		else
			std::cout << "Date not found and no earlier date found." << std::endl;
	}
}

void BitcoinExchange::print()
{
	std::map<std::string, std::string>::iterator it;
	for (it = _data.begin(); it != _data.end(); ++it)
		std::cout << "Fecha: " << it->first << ", Valor: " << it->second << std::endl;
}
