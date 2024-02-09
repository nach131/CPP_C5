
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:22:20 by nmota-bu          #+#    #+#             */
/*   Updated: 2024/01/28 12:20:40 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ColorsFt.hpp"
#include "libftPlus.hpp"
#include <list>
#include "MutantStack.hpp"

template <typename T>
void printM(MutantStack<T> &tmp)
{
	while (!tmp.empty())
	{
		std::cout << tmp.top() << " ";
		tmp.pop();
	}
	std::cout << "\n______" << std::endl;
}

int main()
{

	printStringInCenter("[ Int ]");
	{
		MutantStack<int> myStack;
		myStack.push(5);
		myStack.push(17);
		std::cout << myStack.top() << std::endl;
		myStack.pop();
		std::cout << myStack.size() << std::endl;
		myStack.push(3);
		myStack.push(75);

		MutantStack<int> B(myStack);

		printM(B);
	}
	printStringInCenter("[ Operator = ]");
	{
		MutantStack<int> myStack;
		myStack.push(5);
		myStack.push(17);
		MutantStack<int> B(myStack);

		printM(B);
	}
	printStringInCenter("[ Begin & End ]");
	{
		MutantStack<int> myStack;
		myStack.push(5);
		myStack.push(17);
		myStack.push(42);
		MutantStack<int>::iterator it = myStack.begin();
		MutantStack<int>::iterator ite = myStack.end();

		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}

	printStringInCenter("[ Subject ]");
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737); //[...] mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	printStringInCenter("[ list ]");
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << "Elementos en MutantStack: ";
		for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;

		// Usando std::list para comparación
		std::list<int> l;
		l.push_back(42);
		l.push_back(84);
		std::cout << "Elementos en std::list: ";
		for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
	}

	return 0;
}
