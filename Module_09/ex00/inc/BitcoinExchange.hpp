/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:49:02 by nmota-bu          #+#    #+#             */
/*   Updated: 2024/02/12 18:05:32 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Colors_ft.hpp"

class BitcoinExchange
{
private:
	std::map<std::string, std::string> _data;
	void readCSV(const std::string &filename);
	void pConvert(std::string, float, float);

public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &tmp);
	~BitcoinExchange();
	BitcoinExchange &operator=(const BitcoinExchange &tmp);

	void change(const std::string, float);
	void print();
};

#endif
