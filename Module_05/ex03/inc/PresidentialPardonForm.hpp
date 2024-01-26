/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:48:04 by nmota-bu          #+#    #+#             */
/*   Updated: 2024/01/25 19:22:05 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "iostream"

class PresidentialPardonForm : public AForm
{
private:
	PresidentialPardonForm();
	PresidentialPardonForm &operator=(PresidentialPardonForm const &);

public:
	PresidentialPardonForm(std::string);
	PresidentialPardonForm(PresidentialPardonForm const &);
	~PresidentialPardonForm();
	void execute(Bureaucrat const &) const;
};

#endif
