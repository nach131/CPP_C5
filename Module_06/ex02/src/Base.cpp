/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:09:12 by nmota-bu          #+#    #+#             */
/*   Updated: 2024/01/29 17:59:34 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors_ft.hpp"
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <random>

int Base::getRandomNumber()
{
	std::random_device rd;	// Obtén una semilla aleatoria del dispositivo
	std::mt19937 gen(rd()); // Usa el generador Mersenne Twister con la semilla aleatoria

	// Define la distribución uniforme entre 0 y 2 (ambos inclusive)
	std::uniform_int_distribution<> distribution(0, 2);

	// Genera y devuelve un número aleatorio
	return distribution(gen);
}

Base::Base() { std::cout << "Constructor Base" << std::endl; }

Base::~Base() { std::cout << "Destructor Base" << std::endl; }

Base::Base(const Base &tmp) { *this = tmp; }

Base &Base::operator=(const Base &tmp)
{
	if (this != &tmp)
	{
		;
	}
	return *this;
}

Base *Base::generate(void)
{
	int num = getRandomNumber();
	return (num == 0) ? static_cast<Base *>(new A()) : ((num == 1) ? static_cast<Base *>(new B()) : static_cast<Base *>(new C()));
}

void Base::identify(Base *p)
{
	if (dynamic_cast<A *>(p) != nullptr)
		std::cout << GREEN << "ptr: " << p << " is class A" << RESET << std::endl;
	else if (dynamic_cast<B *>(p) != 0)
		std::cout << GREEN << "ptr: " << p << " is class B" << RESET << std::endl;
	else
		std::cout << GREEN << "ptr: " << p << " is class C" << RESET << std::endl;
}

void Base::identify(Base &p)
{
	if (dynamic_cast<A *>(&p) != nullptr)
		std::cout << YELLOW << "ptr: " << &p << " is class A" << RESET << std::endl;
	else if (dynamic_cast<B *>(&p) != nullptr)
		std::cout << YELLOW << "ptr: " << &p << " is class B" << RESET << std::endl;
	else
		std::cout << YELLOW << "ptr: " << &p << " is class C" << RESET << std::endl;
}
