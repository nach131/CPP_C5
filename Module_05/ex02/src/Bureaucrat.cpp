/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:10:04 by nmota-bu          #+#    #+#             */
/*   Updated: 2024/01/25 11:36:17 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors_ft.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

void Bureaucrat::checkGrade(int grade) const
{
	if (grade < 1)
		throw e_low;
	else if (grade > 150)
		throw e_high;
}

Bureaucrat::Bureaucrat() : _name(""), _grade(150)
{
	std::cout << BURO << "[Bureaucrat]" << GREEN << " - Constructor without parameter" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
	std::cout << BURO << "[Bureaucrat]" << GREEN << " - Constructor" << RESET << std::endl;
	checkGrade(grade);
	this->_grade = grade;
}

Bureaucrat::~Bureaucrat() { std::cout << BURO << "[Bureaucrat]" << RED << " - Destructor" << RESET << std::endl; }

Bureaucrat::Bureaucrat(const Bureaucrat &tmp)
{
	std::cout << BURO << "[Bureaucrat]" << CYAN << " - Copy constructor" << RESET << std::endl;
	*this = tmp;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &tmp)
{
	std::cout << BURO << "[Bureaucrat]" << YELLOW << " - Assignation operator" << RESET << std::endl;

	if (this != &tmp)
	{
		const_cast<std::string &>(_name) = tmp._name;
		_grade = tmp._grade;
	}
	return *this;
}

std::string Bureaucrat::getName() const { return this->_name; }

int Bureaucrat::getGrade() const { return this->_grade; }

std::ostream &operator<<(std::ostream &out, const Bureaucrat &tmp)
{
	out << tmp.getName() << ", bureaucrat grade " << tmp.getGrade();
	return out;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() { return ERROR "[ Exception ] Grade can't be higher than [ 150 ]" RESET; }

const char *Bureaucrat::GradeTooLowException::what() const throw() { return ERROR "[ Exception ] Grade can't be lower than [ 1 ]" RESET; }

void Bureaucrat::up(int num)
{
	checkGrade(num + this->_grade);
	this->_grade += num;
}

void Bureaucrat::down(int num)
{
	checkGrade(this->_grade - num);
	this->_grade -= num;
}

void Bureaucrat::signForm(Form &tmp)
{
	if (tmp.getSigned() == "false")
		try
		{
			tmp.beSigned(*this);
			std::cout << this->getName() << " signs " << tmp.getName() << std::endl;
		}
		catch (Form::GradeTooLowException &e)
		{
			std::cout << this->getName() << " couldn’t sign " << tmp.getName() << " because " << e.what() << std::endl;
		}
	else
		std::cout << "Form : " << tmp.getName() << " is already signed" << std::endl;
}
