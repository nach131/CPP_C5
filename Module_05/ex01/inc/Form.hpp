/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:51:13 by nmota-bu          #+#    #+#             */
/*   Updated: 2024/01/23 16:56:32 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "iostream"

class Form
{
private:
	const std::string _nameForm;
	bool _signed;
	const int _gradeSign;
	const int _gradeExe;

public:
	Form();
	Form(const Form &);
	~Form();
	Form &operator=(const Form &);
};

#endif
