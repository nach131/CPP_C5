
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

#include "Colors_ft.hpp"
#include "libftP.hpp"
#include "RPN.hpp"
#include <iostream>

int main(int n, char **str)
{
	try
	{
		if (n != 2)
			throw std::runtime_error("Error: You must provide an operation in RPN notation as an argument.");

		printStringInCenter(str[1]);
		RPN calc(str[1]);
	}
	catch (const std::exception &ex)
	{
		std::cerr << ERROR << ex.what() << RESET << std::endl;
	}

	return EXIT_SUCCESS;
}
