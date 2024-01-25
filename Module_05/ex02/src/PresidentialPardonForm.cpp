/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:10:59 by nmota-bu          #+#    #+#             */
/*   Updated: 2024/01/25 19:22:27 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Colors_ft.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string name) : AForm(name, 25, 5) { std::cout << PRE << "[Presidential]" << GREEN << " - Constructor" << RESET << std::endl; }

PresidentialPardonForm::~PresidentialPardonForm() { std::cout << PRE << "[Presidential]" << RED << " - Destructor" << RESET << std::endl; }

void PresidentialPardonForm::execute(Bureaucrat const &bure) const
{

	AForm::execute(bure);
	std::cout << bure.getName() << " has been pardonned by Zafod Beeblebrox" << std::endl;
}
