/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:10:04 by nmota-bu          #+#    #+#             */
/*   Updated: 2024/01/25 17:34:41 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors_ft.hpp"
#include "Form.hpp"
#include "Bureaucrat.hpp"

void Form::checkGrade(int grade, int exe) const
{
	if (grade < 1 || exe < 1)
		throw e_low;
	else if (grade > 150 || exe > 150)
		throw e_high;
}

Form::Form() : _name(""), _gradeSig(0), _gradeExe(0), _isSigned(false) {}

Form::Form(const std::string name, int grade, int exe) : _name(name), _gradeSig(grade), _gradeExe(exe), _isSigned(false)
{
	std::cout << BURO << "[Form]" << GREEN << " - Constructor" << RESET << std::endl;
	checkGrade(grade, exe);
}

Form::Form(const Form &tmp) : _name(tmp._name), _gradeSig(tmp._gradeSig), _gradeExe(tmp._gradeExe), _isSigned(tmp._isSigned) {}

Form::~Form() { std::cout << BURO << "[Form]" << RED << " - Destructor" << RESET << std::endl; }

Form &Form::operator=(const Form &tmp)
{
	std::cout << BURO << "[Form]" << YELLOW << " - Assignation operator" << RESET << std::endl;

	if (this != &tmp)
	{
		const_cast<std::string &>(_name) = tmp._name;
		const_cast<int &>(_gradeSig) = tmp._gradeSig;
		const_cast<int &>(_gradeExe) = tmp._gradeExe;
		this->_isSigned = tmp._isSigned;
	}
	return *this;
}

std::string Form::getName() const { return this->_name; }

std::string Form::getSigned() const
{
	if (this->_isSigned)
		return "true";
	else
		return "false";
}

int Form::getGradeSig() const { return this->_gradeSig; }
int Form::getGradeExe() const { return this->_gradeExe; }

std::ostream &operator<<(std::ostream &out, const Form &tmp)
{
	out << "    [ Info Form ]" << std::endl;
	out << "Name: " << tmp.getName() << "\n";
	out << "Grade to siged: " << tmp.getGradeSig() << "\n";
	out << "Grade to execute: " << tmp.getGradeExe() << "\n";
	out << "Signed: " << tmp.getSigned() << "\n";
	out << "▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂";

	return out;
}

const char *Form::GradeTooHighException::what() const throw() { return ERROR "[ Exception ] Grade too high" RESET; }

const char *Form::GradeTooLowException::what() const throw() { return ERROR "[ Exception ] Grade too low" RESET; }

const char *Form::IsSignedExeption::what() const throw() { return ERROR "[ Exception ] is already signed" RESET; }

void Form::beSigned(Bureaucrat &tmp)
{
	if (tmp.getGrade() <= this->_gradeSig)
		this->_isSigned = true;
	else
		throw e_low;
}
