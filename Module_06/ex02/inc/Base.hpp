/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:06:22 by nmota-bu          #+#    #+#             */
/*   Updated: 2024/01/29 15:37:19 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>

class Base
{
private:
	int getRandomNumber();

public:
	Base();
	Base(const Base &);
	virtual ~Base();
	Base &operator=(const Base &);

	Base *generate(void);
	void identify(Base *p);
	void identify(Base &p);
};

#endif
