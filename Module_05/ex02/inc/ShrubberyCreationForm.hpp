/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:48:04 by nmota-bu          #+#    #+#             */
/*   Updated: 2024/01/25 21:33:49 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "iostream"

class ShrubberyCreationForm : public AForm
{
private:
	ShrubberyCreationForm();
	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &);

public:
	ShrubberyCreationForm(std::string);
	ShrubberyCreationForm(ShrubberyCreationForm const &);
	~ShrubberyCreationForm();
	void execute(Bureaucrat const &) const;
};

#endif
