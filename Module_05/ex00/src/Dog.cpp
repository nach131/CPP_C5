/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 12:42:58 by nmota-bu          #+#    #+#             */
/*   Updated: 2024/01/07 14:57:34 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Colors_ft.hpp"

Dog::Dog()
{
	std::cout << DOG_C << "[Dog]" << GREEN << " - Default constructor called without parameter" << RESET << std::endl;
	Animal::_type = "Dog";
}

Dog::Dog(const Dog &tmp)
{
	std::cout << DOG_C << "[Dog]" << CYAN << " - Copy constructor called" << RESET << std::endl;
	*this = tmp;
}

Dog::~Dog() { std::cout << DOG_C << "[Dog]" << RED << " - Destructor called" << RESET << std::endl; }

Dog &Dog::operator=(const Dog &tmp)
{
	std::cout << DOG_C << "[Dog]" << YELLOW << " - Assignation operator called" << RESET << std::endl;
	if (this != &tmp)
	{
		Animal::_type = tmp.Animal::_type;
	}
	return *this;
}

void Dog::makeSound() const
{
	std::cout << DOG_C << "[Dog]" << RESET << ORANGE << " Wooof... Wooof...." << RESET << std::endl;
}
