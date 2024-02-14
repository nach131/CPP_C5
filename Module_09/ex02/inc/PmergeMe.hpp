/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 20:47:47 by nmota-bu          #+#    #+#             */
/*   Updated: 2024/02/14 10:48:53 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <limits.h>

class PmergeMe
{
private:
	bool _sorted;
	std::vector<int> _vec;
	// std::list<int> _lst;
	std::string _token;
	PmergeMe();
	void start();
	bool isValidToken(const std::string &token);
	void print();
	void sortVector();

public:
	PmergeMe(std::string);
	PmergeMe(const PmergeMe &);
	~PmergeMe();
	PmergeMe &operator=(const PmergeMe &);
};

#endif
