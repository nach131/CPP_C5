/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:10:04 by nmota-bu          #+#    #+#             */
/*   Updated: 2024/01/24 20:05:01 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors_ft.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

void AForm::checkGrade(int grade, int exe) const
{
	if (grade < 1 || exe < 1)
		throw e_low;
	else if (grade > 150 || exe > 150)
		throw e_high;
}

AForm::AForm() : _name(""), _gradeSig(0), _gradeExe(0), _isSigned(false) {}

AForm::AForm(const std::string name, int grade, int exe) : _name(name), _gradeSig(grade), _gradeExe(exe), _isSigned(false)
{
	std::cout << BURO << "[AForm]" << GREEN << " - Constructor" << RESET << std::endl;
	checkGrade(grade, exe);
}

AForm::AForm(const AForm &tmp) : _name(tmp._name), _gradeSig(tmp._gradeSig), _gradeExe(tmp._gradeExe), _isSigned(tmp._isSigned) {}

AForm::~AForm() { std::cout << BURO << "[AForm]" << RED << " - Destructor" << RESET << std::endl; }

AForm &AForm::operator=(const AForm &tmp)
{
	std::cout << BURO << "[AForm]" << YELLOW << " - Assignation operator" << RESET << std::endl;

	if (this != &tmp)
	{
		const_cast<std::string &>(_name) = tmp._name;
		const_cast<int &>(_gradeSig) = tmp._gradeSig;
		const_cast<int &>(_gradeExe) = tmp._gradeExe;
		this->_isSigned = tmp._isSigned;
	}
	return *this;
}

std::string AForm::getName() const { return this->_name; }

std::string AForm::getSigned() const
{
	if (this->_isSigned)
		return "true";
	else
		return "false";
}

int AForm::getGradeSig() const { return this->_gradeSig; }
int AForm::getGradeExe() const { return this->_gradeExe; }

std::ostream &operator<<(std::ostream &out, const AForm &tmp)
{
	out << "    [ Info AForm ]" << std::endl;
	out << "Name: " << tmp.getName() << "\n";
	out << "Grade to siged: " << tmp.getGradeSig() << "\n";
	out << "Grade to execute: " << tmp.getGradeExe() << "\n";
	out << "Signed: " << tmp.getSigned() << "\n";
	out << "▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄";

	return out;
}

const char *AForm::GradeTooHighException::what() const throw() { return ERROR "[ Exception ] Grade too high" RESET; }

const char *AForm::GradeTooLowException::what() const throw() { return ERROR "[ Exception ] Grade too low" RESET; }

void AForm::beSigned(Bureaucrat &tmp)
{
	if (tmp.getGrade() <= this->_gradeSig)
		this->_isSigned = true;
	else
		throw e_low;
}
