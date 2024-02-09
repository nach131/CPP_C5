/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 20:58:15 by nmota-bu          #+#    #+#             */
/*   Updated: 2024/02/09 12:36:10 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTAC_HPP
#define MUTANTSTAC_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
private:
public:
	MutantStack(){};
	MutantStack(const MutantStack &tmp) { *this = tmp; };
	~MutantStack(){};
	MutantStack &operator=(const MutantStack &tmp)
	{
		if (this != &tmp)
			std::stack<T>::operator=(tmp);
		return *this;
	}

	typedef typename std::stack<T>::container_type::iterator iterator;

	iterator begin() { return std::stack<T>::c.begin(); }

	iterator end() { return std::stack<T>::c.end(); }
};

#endif
