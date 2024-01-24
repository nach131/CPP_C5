/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:07:14 by nmota-bu          #+#    #+#             */
/*   Updated: 2024/01/24 13:06:26 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "iostream"

class Form
{
private:
	const std::string _name;
	const int _gradeSig;
	const int _gradeExe;
	bool _isSigned;
	void checkGrade(int grade) const;
	Form();

public:
	Form(const std::string, int, int);
	Form(const Form &);
	~Form();
	Form &operator=(const Form &);

	std::string getName() const;
	std::string getSigned() const;
	int getGradeSig() const;
	int getGradeExe() const;

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	} e_high;

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	} e_low;
};

std::ostream &operator<<(std::ostream &out, const Form &tmp);

#endif
