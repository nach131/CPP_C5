/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 02:03:17 by nmota-bu          #+#    #+#             */
/*   Updated: 2024/01/28 19:56:27 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors_ft.hpp"
#include "Convert.hpp"
#include <iomanip>
#include <cmath>

Convert::Convert() {}

Convert::~Convert() {}

Convert::Convert(const Convert &tmp) { *this = tmp; }

Convert &Convert::operator=(const Convert &tmp)
{
	if (this != &tmp)
	{
		;
	}
	return *this;
}

Convert::Convert(char ch, bool flag)
{
	if (flag)
		std::cout << PINK << "char:" << RED << "   impossible" << RESET << std::endl;
	else if (ch < ' ' || ch > '~')
		std::cout << PINK << "char:" << RED << "   Non displayable" << RESET << std::endl;
	else
		std::cout << PINK << "char:" << GREEN << "   '" << ch << "'" << RESET << std::endl;
}

Convert::Convert(int integer, bool flag)
{
	if (flag)
		std::cout << PINK << "int:" << RED << "    impossible" << RESET << std::endl;
	else
		std::cout << PINK << "int:" << GREEN << "    " << integer << RESET << std::endl;
}

Convert::Convert(double decimal, bool flag)
{
	(void)flag;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << PINK << "double:" << GREEN << " " << decimal << RESET << std::endl;
}

Convert::Convert(float floating, bool flag)
{
	(void)flag;
	if (std::isnan(floating))
		std::cout << PINK << "float:" << GREEN << "  nanf" << RESET << std::endl;
	else
	{
		std::cout << std::fixed << std::setprecision(1);
		std::cout << PINK << "float:" << GREEN << "  " << floating << "f" << RESET << std::endl;
	}
}
