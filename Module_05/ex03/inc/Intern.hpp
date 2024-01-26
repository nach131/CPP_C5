/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:45:29 by nmota-bu          #+#    #+#             */
/*   Updated: 2024/01/26 13:55:23 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "iostream"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
private:
	static AForm *createPresidentialForm(std::string target);
	static AForm *createRobotomyForm(std::string target);
	static AForm *createShrubberyForm(std::string target);

public:
	Intern();
	Intern(const Intern &);
	~Intern();
	Intern &operator=(const Intern &);
	AForm *makeForm(std::string formName, std::string target);

	class NotFoundException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	} NotFound;
};

#endif
