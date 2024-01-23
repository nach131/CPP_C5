/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:51:29 by nmota-bu          #+#    #+#             */
/*   Updated: 2024/01/23 22:21:55 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Colors_ft.hpp"

void Form::checkGrade(int gradeSig, int gradeExe) const
{
	if (gradeSig < 1 || gradeExe < 1)
		throw e_low;
	else if (gradeSig > 150 || gradeExe > 150)
		throw e_high;
}

// Form::Form() : _name(""), _signed(false), _gradeSig(0), _gradeExe(0)
// {
// 	std::cout << FORM << "[Form]" << GREEN << "       - Constructor without parameter" << RESET << std::endl;
// }

Form::Form(std::string name, int s_grade, int e_grade) : _name(name), _gradeSig(s_grade), _gradeExe(e_grade)
{

	std::cout << FORM << "[Form]" << GREEN << "       - Constructor" << RESET << std::endl;
	checkGrade(s_grade, e_grade);
	// const_cast<std::string &>(this->_nameForm) = name;
	// this->_gradeSig = gradeSig;
	// this->_gradeExe = gradeExe;
}

Form::~Form()
{
	std::cout << FORM << "[Form]" << RED << "       - Destructor" << RESET << std::endl;
}

// Form &Form::operator=(const Form &tmp)
// {
// 	std::cout << FORM << "[Form]" << YELLOW << "       - Assignation operator" << RESET << std::endl;

// 	if (this != &tmp)
// 	{
// 		;
// 	}
// 	return *this;
// }

std::string Form::getName() const { return this->_name; }

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << "------------- Form Info -------------" << std::endl;
	out << "Form name: " << form.getName() << std::endl;
	//   << "Grade to sign: " << form.getGradeToSign() << std::endl
	//   << "Grade to execute: " << form.getGradeToExecute();
	return out;
}

const char *Form::GradeTooHighException::what() const throw() { return ERROR "[ Exception ] Grade can't be higher than [ 150 ]" RESET; }

const char *Form::GradeTooLowException::what() const throw() { return ERROR "[ Exception ] Grade can't be lower than [ 1 ]" RESET; }
