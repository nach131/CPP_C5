
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
#include "libft_p.hpp"
#include "Convert.hpp"
#include <cmath>

int err_argc()
{
	system("clear");
	std::cerr << RED << "Missing argument:" << RESET << std::endl;
	std::cout << ERROR << "[Number to convert]" RESET << std::endl;
	return EXIT_FAILURE;
}

bool ctr_flag(long double num)
{
	if (std::isinf(num) || std::isnan(num))
		return true;
	return false;
}

void print()
{
	std::cout << PINK << "char:" << RED << "   impossible" << RESET << std::endl;
	std::cout << PINK << "int:" << RED << "    impossible" << RESET << std::endl;
	std::cout << PINK << "flot:" << RED << "   impossible" << RESET << std::endl;
	std::cout << PINK << "double:" << RED << " impossible" << RESET << std::endl;
}

int main(int n, char **str)
{
	if (n != 2)
		return err_argc();

	std::string menu = "Original: " + std::string(str[1]);
	printStringInCenter(menu);

	char *endptr;
	long double tmp = strtod(str[1], &endptr);
	bool flag = ctr_flag(tmp);

	if (str[1] == endptr || strlen(endptr) > 1)
		print();
	else
	{
		Convert a(static_cast<char>(tmp), flag);
		Convert b(static_cast<int>(tmp), flag);
		Convert d(static_cast<float>(tmp), flag);
		Convert c(static_cast<double>(tmp), flag);
	}

	return 0;
}
