/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:07:14 by nmota-bu          #+#    #+#             */
/*   Updated: 2024/01/30 16:32:36 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "iostream"

class Bureaucrat;

class AForm
{
private:
	const std::string _name;
	const int _gradeSig;
	const int _gradeExe;
	bool _isSigned;
	void checkGrade(int grade, int exe) const;
	AForm();

public:
	AForm(const std::string, int, int);
	AForm(const AForm &);
	virtual ~AForm();
	AForm &operator=(const AForm &);

	std::string getName() const;
	std::string getSigned() const;
	int getGradeSig() const;
	int getGradeExe() const;
	void beSigned(Bureaucrat &);

	virtual void execute(Bureaucrat const &) const;

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

	class IsSignedExeption : public std::exception
	{
	public:
		virtual const char *what() const throw();
	} e_signed;

	class NotSignedExeption : public std::exception
	{
	public:
		virtual const char *what() const throw();
	} e_Nsigned;
};

std::ostream &operator<<(std::ostream &out, const AForm &tmp);

#endif
