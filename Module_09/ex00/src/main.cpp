
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

int main(int n, char **str)
{

	if (n != 2)
	{
		std::cerr << ERROR << "Necessary movement file" << RESET << std::endl;
		return EXIT_FAILURE;
	}

	BitcoinExchange a;

	a.change("2012-01-11", 1);
	// BitcoinExchange b;

	// b = a;

	// b.print();
	// a.print();
	(void)str;

	return 0;
}
