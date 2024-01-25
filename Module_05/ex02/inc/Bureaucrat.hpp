/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:07:14 by nmota-bu          #+#    #+#             */
/*   Updated: 2024/01/25 17:41:53 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "iostream"

class AForm;

class Bureaucrat
{
private:
	const std::string _name;
	int _grade;
	void checkGrade(int grade) const;

public:
	Bureaucrat();
	Bureaucrat(const std::string, int);
	Bureaucrat(const Bureaucrat &);
	~Bureaucrat();
	Bureaucrat &operator=(const Bureaucrat &);

	std::string getName() const;
	int getGrade() const;
	void up(int);
	void down(int);
	void signForm(AForm &);

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

std::ostream &operator<<(std::ostream &out, const Bureaucrat &tmp);

#endif
