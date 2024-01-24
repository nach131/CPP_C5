/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:10:04 by nmota-bu          #+#    #+#             */
/*   Updated: 2024/01/24 09:48:33 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors_ft.hpp"
#include "Form.hpp"

void Form::checkGrade(int grade) const
{
	if (grade < 1)
		throw e_low;
	else if (grade > 150)
		throw e_high;
}

Form::Form(const std::string name, int grade) : _name(name), _grade(grade)
{
	std::cout << BURO << "[Form]" << GREEN << " - Constructor" << RESET << std::endl;
	checkGrade(grade);
}

Form::Form(const Form &tmp) : _name(tmp._name), _grade(tmp._grade) {}

Form::~Form() { std::cout << BURO << "[Form]" << RED << " - Destructor" << RESET << std::endl; }

Form &Form::operator=(const Form &tmp)
{
	std::cout << BURO << "[Form]" << YELLOW << " - Assignation operator" << RESET << std::endl;

	if (this != &tmp)
	{
		const_cast<std::string &>(_name) = tmp._name;
		const_cast<int &>(_grade) = tmp._grade;
	}
	return *this;
}

std::string Form::getName() const { return this->_name; }

int Form::getGrade() const { return this->_grade; }

std::ostream &operator<<(std::ostream &out, const Form &tmp)
{
	out << tmp.getName() << ", Form grade " << tmp.getGrade();
	return out;
}

const char *Form::GradeTooHighException::what() const throw() { return ERROR "[ Exception ] Grade can't be higher than [ 150 ]" RESET; }

const char *Form::GradeTooLowException::what() const throw() { return ERROR "[ Exception ] Grade can't be lower than [ 1 ]" RESET; }

void Form::up(int num)
{
	const_cast<int &>(_grade) -= num;
	checkGrade(_grade);
}

void Form::down(int num)
{
	const_cast<int &>(_grade) += num;
	checkGrade(_grade);
}
