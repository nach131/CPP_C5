/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:07:14 by nmota-bu          #+#    #+#             */
/*   Updated: 2024/01/24 09:48:21 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "iostream"

class Form
{
private:
	const std::string _name;
	const int _grade;
	void checkGrade(int grade) const;
	// Form();

public:
	Form(const std::string, int);
	Form(const Form &);
	~Form();
	Form &operator=(const Form &);

	std::string getName() const;
	int getGrade() const;
	void up(int);
	void down(int);

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
