
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
#include "whatever.hpp"

int main()
{

	printStringInCenter("[ float ]");
	{
		float a = 42.4242f;
		float b = 12.1212f;

		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;

		my::swap(a, b);
		std::cout << "swap" << std::endl;
		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;

		std::cout << "min: " << my::min(a, b) << std::endl;
		std::cout << "max: " << my::max(a, b) << std::endl;
	}
	printStringInCenter("[ int ]");
	{
		float a = 42;
		float b = 12;

		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;

		my::swap(a, b);
		std::cout << "swap" << std::endl;
		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;

		std::cout << "min: " << my::min(a, b) << std::endl;
		std::cout << "max: " << my::max(a, b) << std::endl;
	}
	printStringInCenter("[ string ]");
	{
		std::string a = "42 Barcelona";
		std::string b = "22 Paris";

		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;

		my::swap(a, b);
		std::cout << "swap" << std::endl;
		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;

		std::cout << "min: " << my::min(a, b) << std::endl;
		std::cout << "max: " << my::max(a, b) << std::endl;
	}
	printStringInCenter("[ subject ]");
	{
		int a = 2;
		int b = 3;
		my::swap(a, b);
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << my::min(a, b) << std::endl;
		std::cout << "max( a, b ) = " << my::max(a, b) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		my::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << my::min(c, d) << std::endl;
		std::cout << "max( c, d ) = " << my::max(c, d) << std::endl;
	}

	return 0;
}
