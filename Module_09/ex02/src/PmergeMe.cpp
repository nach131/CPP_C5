/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 20:51:10 by nmota-bu          #+#    #+#             */
/*   Updated: 2024/02/13 22:38:11 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(std::string ori)
{
	std::istringstream iss(ori);
	while (iss >> _token)
	{
		if (isValidToken(_token))
		{
			long value = std::strtol(_token.c_str(), NULL, 10);
			if (value >= INT_MAX || value <= INT_MIN)
				throw std::runtime_error("Error: Some value is larger or smaller than integer");
			else
				_vec.push_back(static_cast<int>(value));
		}
		else
			throw std::runtime_error("Error: Some value is not an integer.");
	}
}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) { *this = other; }

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
		// this->_stack = other._stack;
		;
	return *this;
}

bool PmergeMe::isValidToken(const std::string &token)
{
	for (std::string::const_iterator it = token.begin(); it != token.end(); ++it)
	{
		char c = *it;
		if (!(c >= '0' && c <= '9'))
			return false;
	}
	return true;
}

void PmergeMe::print()
{
	for (size_t i = 0; i < _vec.size(); i++)
		std::cout << _vec[i] << " ";
	std::cout << std::endl;
}
