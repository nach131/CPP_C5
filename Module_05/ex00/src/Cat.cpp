/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 12:39:25 by nmota-bu          #+#    #+#             */
/*   Updated: 2024/01/07 14:55:32 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Colors_ft.hpp"

Cat::Cat()
{
	std::cout << CAT_C << "[Cat]" << GREEN << " - Default constructor called without parameter" << RESET << std::endl;
	Animal::_type = "Cat";
}

Cat::Cat(const Cat &tmp)
{
	std::cout << CAT_C << "[Cat]" << CYAN << " - Copy constructor called" << RESET << std::endl;
	*this = tmp;
}

Cat::~Cat() { std::cout << CAT_C << "[Cat]" << RED << " - Destructor called" << RESET << std::endl; }

Cat &Cat::operator=(const Cat &tmp)
{
	std::cout << CAT_C << "[Cat]" << YELLOW << " - Assignation operator called" << RESET << std::endl;
	if (this != &tmp)
	{
		Animal::_type = tmp.Animal::_type;
	}
	return *this;
}

void Cat::makeSound() const
{
	std::cout << CAT_C << "[Cat]" << RESET << ORANGE << " Miauuu... Miauuu...." << RESET << std::endl;
}
