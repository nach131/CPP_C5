/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:10:04 by nmota-bu          #+#    #+#             */
/*   Updated: 2024/01/24 13:05:10 by nmota-bu         ###   ########.fr       */
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

Form::Form() : _name(""), _gradeSig(0), _gradeExe(0), _isSigned(false) {}

Form::Form(const std::string name, int grade, int exe) : _name(name), _gradeSig(grade), _gradeExe(exe), _isSigned(false)
{
	std::cout << BURO << "[Form]" << GREEN << " - Constructor" << RESET << std::endl;
	checkGrade(grade);
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
	out << "--------Info Form-------" << std::endl;
	out << "Name form: " << tmp.getName() << "\n";
	out << "Form grade to siged: " << tmp.getGradeSig() << "\n";
	out << "Form grade Execute: " << tmp.getGradeExe() << "\n";
	out << "Form signed: " << tmp.getSigned();

	return out;
}

const char *Form::GradeTooHighException::what() const throw() { return ERROR "[ Exception ] Grade can't be higher than [ 150 ]" RESET; }

const char *Form::GradeTooLowException::what() const throw() { return ERROR "[ Exception ] Grade can't be lower than [ 1 ]" RESET; }
