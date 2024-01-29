/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:24:55 by nmota-bu          #+#    #+#             */
/*   Updated: 2024/01/29 21:42:06 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

namespace my
{
	template <typename T>
	void swap(T &a, T &b)
	{
		T tmp = a;
		a = b;
		b = tmp;
	}

	template <typename T>
	T min(T &a, T &b) { return a < b ? a : b; }

	template <typename T>
	T max(T &a, T &b) { return a > b ? a : b; }
}

#endif
