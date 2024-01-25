/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:48:04 by nmota-bu          #+#    #+#             */
/*   Updated: 2024/01/25 21:25:55 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "iostream"

class RobotomyRequestForm : public AForm
{
private:
	RobotomyRequestForm();
	RobotomyRequestForm &operator=(RobotomyRequestForm const &);

public:
	RobotomyRequestForm(std::string);
	RobotomyRequestForm(RobotomyRequestForm const &);
	~RobotomyRequestForm();
	void execute(Bureaucrat const &) const;
};

#endif
