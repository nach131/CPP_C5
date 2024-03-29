/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:37:07 by nmota-bu          #+#    #+#             */
/*   Updated: 2024/02/01 20:44:43 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include "Colors_ft.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
// #include <algorithm>
#include <typeinfo>

template <typename T>
void easyfind(const T &container, int n)
{

	typename T::const_iterator it = std::find(container.begin(), container.end(), n);

	if (it != container.end())
		std::cout << GREEN << "Value '" + std::to_string(n) + "' exists." << RESET << std::endl;
	else
		throw std::string("Value '" + std::to_string(n) + "' doesn't exist in the container.");
}

template <typename T>
void easyfindMap(const T &container, int n)
{

	typename T::const_iterator it = container.find(n);

	if (it != container.end())
		std::cout << GREEN << "Value '" + std::to_string(n) + "' exists." << RESET << std::endl;
	else
		throw std::string("Value '" + std::to_string(n) + "' doesn't exist in the container.");
}

#endif
