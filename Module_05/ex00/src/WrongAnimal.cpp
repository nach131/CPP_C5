/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 12:23:51 by nmota-bu          #+#    #+#             */
/*   Updated: 2024/01/07 15:35:38 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "Colors_ft.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << ANIMAL_C << "[WrongAnimal]" << GREEN << " - Default constructor called without parameter" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &tmp)
{
	std::cout << ANIMAL_C << "[WrongAnimal]" << CYAN << " - Copy constructor called" << RESET << std::endl;
	*this = tmp;
}

WrongAnimal::~WrongAnimal() { std::cout << ANIMAL_C << "[WrongAnimal]" << RED << " - Destructor called" << RESET << std::endl; }

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &tmp)
{
	std::cout << ANIMAL_C << "[WrongAnimal]" << YELLOW << " - Assignation operator called" << RESET << std::endl;
	if (this != &tmp)
	{
		_type = tmp._type;
	}
	return *this;
}

void WrongAnimal::makeSound() const
{
	std::cout << ANIMAL_C << "[WrongAnimal]" << RESET << ORANGE << " WrongAnimal is class it has no sound" << RESET << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (_type);
}
