/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 12:38:47 by nmota-bu          #+#    #+#             */
/*   Updated: 2024/01/07 14:55:07 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "iostream"

class Cat : public Animal
{

public:
	Cat();
	Cat(const Cat &);
	~Cat();
	Cat &operator=(const Cat &);
	void makeSound() const;
};

#endif
