/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 20:47:47 by nmota-bu          #+#    #+#             */
/*   Updated: 2024/02/13 22:33:52 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <vector>
#include <limits.h>

class PmergeMe
{
private:
	std::vector<int> _vec;
	std::string _token;
	PmergeMe();
	bool isValidToken(const std::string &token);

public:
	PmergeMe(std::string);
	PmergeMe(const PmergeMe &);
	~PmergeMe();
	PmergeMe &operator=(const PmergeMe &);
	void print();
};

#endif
