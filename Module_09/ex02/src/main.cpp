
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

#include <iostream>
#include "Colors_ft.hpp"
#include <stack>
#include "libftP.hpp"
#include <sstream>

bool isValidToken(const std::string &token)
{
	for (std::string::const_iterator it = token.begin(); it != token.end(); ++it)
	{
		char c = *it;
		if (!(c >= '0' && c <= '9') && c != '+' && c != '-' && c != '*' && c != '/')
			return false;
	}
	return true;
}

bool isOperator(const std::string &token)
{
	return token == "+" || token == "-" || token == "*" || token == "/";
}

int main(int n, char **str)
{
	if (n != 2)
	{
		std::cerr << ERROR << "Error: insert operation RPN" << RESET << std::endl;
		return EXIT_SUCCESS;
	}
	printStringInCenter(str[1]);

	std::istringstream iss(str[1]);
	std::string token;
	std::stack<int> stack;

	while (iss >> token)
	{
		if (isValidToken(token))
		{
			if (isOperator(token))
			{
				int operand2 = stack.top();
				stack.pop();
				int operand1 = stack.top();
				stack.pop();

				if (token == "+")
					stack.push(operand1 + operand2);
				else if (token == "-")
					stack.push(operand1 - operand2);
				else if (token == "*")
					stack.push(operand1 * operand2);
				else if (token == "/")
					stack.push(operand1 / operand2);
			}
			else
				stack.push(atoi(token.c_str()));
		}
		else
		{
			std::cerr << ERROR << "Error: Invalid token." << RESET << std::endl;
			return EXIT_SUCCESS;
		}
	}

	std::cout << stack.top() << std::endl;

	return EXIT_SUCCESS;
}
