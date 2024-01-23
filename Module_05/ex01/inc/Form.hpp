/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:51:13 by nmota-bu          #+#    #+#             */
/*   Updated: 2024/01/23 22:12:35 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "iostream"

class Form
{
private:
	std::string const _name;
	bool _signed;
	int const _gradeSig;
	int const _gradeExe;
	Form();

public:
	Form(const std::string name, int gradeSig, int gradeExe);
	// Form(const Form &);
	~Form();
	// Form &operator=(const Form &);

	void checkGrade(int, int) const;

	std::string getName() const;
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

std::ostream &operator<<(std::ostream, const Form &tmp);

#endif
