/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:25:17 by nmota-bu          #+#    #+#             */
/*   Updated: 2024/02/03 11:06:44 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <limits.h>
#include <vector>

class Span
{
private:
	Span();
	std::vector<int> _numbers;

public:
	unsigned int size;
	Span(unsigned int N);
	~Span();
	Span(const Span &);
	Span &operator=(const Span &);

	// int &operator[](size_t);

	void addNumber(int);
	int shortestSpan() const;
	int longestSpan() const;

	void printValues() const;
	void printSort() const;
	unsigned int getSize() const;	  // Items in vector
	unsigned int getCapacity() const; // Size vector
};

// std::ostream &operator<<(std::ostream &os, const Span &span);

#endif

