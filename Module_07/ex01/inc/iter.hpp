/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 21:45:57 by nmota-bu          #+#    #+#             */
/*   Updated: 2024/01/29 23:13:40 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

struct Person
{
	std::string name;
	int power;
};

// Sobrecarga del operador << para imprimir objetos de tipo Person
std::ostream &operator<<(std::ostream &os, const Person &person)
{
	os << "Name: " << person.name << ", Power: " << person.power;
	return os;
}

namespace my
{
	template <typename T>
	void iter(T *arr, size_t size, void (*f)(const T &))
	{
		if (arr)
		{
			for (size_t i = 0; i < size; i++)
				f(arr[i]);
		}
	}

	template <typename T>
	void printItem(const T &i) { std::cout << i << std::endl; }

	// template <typename T>
	// void printItem(const T *ptr) { std::cout << *ptr << std::endl; }
}

#endif
