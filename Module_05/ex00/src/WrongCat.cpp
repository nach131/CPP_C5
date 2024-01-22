/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 12:39:25 by nmota-bu          #+#    #+#             */
/*   Updated: 2024/01/07 15:38:52 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Colors_ft.hpp"

WrongCat::WrongCat()
{
	std::cout << CAT_C << "[WrongCat]" << GREEN << " - Default constructor called without parameter" << RESET << std::endl;
	WrongAnimal::_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &tmp)
{
	std::cout << CAT_C << "[WrongCat]" << CYAN << " - Copy constructor called" << RESET << std::endl;
	*this = tmp;
}

WrongCat::~WrongCat() { std::cout << CAT_C << "[WrongCat]" << RED << " - Destructor called" << RESET << std::endl; }

WrongCat &WrongCat::operator=(const WrongCat &tmp)
{
	std::cout << CAT_C << "[WrongCat]" << YELLOW << " - Assignation operator called" << RESET << std::endl;
	if (this != &tmp)
	{
		WrongAnimal::_type = tmp.WrongAnimal::_type;
	}
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << CAT_C << "[WrongCat]" << RESET << ORANGE << " Miauuu... Miauuu...." << RESET << std::endl;
}
