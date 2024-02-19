/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:52:56 by nmota-bu          #+#    #+#             */
/*   Updated: 2024/02/19 14:00:43 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

bool RPN::isValidRpn(const std::string &ori)
{
    std::istringstream iss(ori);

    int num = 0;
    int oper = 0;
    int pos = 0;

    std::string token;
    while (iss >> token)
    {
        if (pos == 1 && isOperator(token))
            return false;
        if (isOperator(token))
            oper++;
        else if (isValidToken(token))
            num++;
        pos++;
    }
    return (num - oper) == 1;
}

RPN::RPN(const std::string &ori)
{
    if (isValidRpn(ori))
    {
        std::istringstream iss(ori);
        while (iss >> _token)
        {
            if (isOperator(_token))
            {
                int operand2 = _stack.top();
                _stack.pop();
                int operand1 = _stack.top();
                _stack.pop();

                if (_token == "+")
                    _stack.push(operand1 + operand2);
                else if (_token == "-")
                    _stack.push(operand1 - operand2);
                else if (_token == "*")
                    _stack.push(operand1 * operand2);
                else if (_token == "/")
                    _stack.push(operand1 / operand2);
            }
            else
                _stack.push(atoi(_token.c_str()));
        }
        std::cout << _stack.top() << std::endl;
    }
    else
        throw std::runtime_error("Erro: The argument is not valid RPN.");
}

RPN::RPN(RPN const &other) { *this = other; }

RPN &RPN::operator=(RPN const &other)
{
    if (this != &other)
        this->_stack = other._stack;
    return *this;
}

RPN::~RPN() {}

bool RPN::isValidToken(const std::string &token)
{
    for (std::string::const_iterator it = token.begin(); it != token.end(); ++it)
    {
        char c = *it;
        if (!(c >= '0' && c <= '9') && c != '+' && c != '-' && c != '*' && c != '/')
            return false;
    }
    return true;
}

bool RPN::isOperator(const std::string &token)
{
    return token == "+" || token == "-" || token == "*" || token == "/";
}
