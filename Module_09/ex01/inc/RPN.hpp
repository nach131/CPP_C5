/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:50:58 by nmota-bu          #+#    #+#             */
/*   Updated: 2024/02/15 10:15:33 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors_ft.hpp"
#include <stack>
#include <iostream>
#include <sstream>

class RPN
{
private:
    std::stack<int> _stack;
    std::string _token;
    RPN();
    bool isValidToken(const std::string &token);
    bool isOperator(const std::string &token);
    bool isValidRpn(const std::string &);

public:
    RPN(const std::string &);
    RPN(RPN const &other);
    RPN &operator=(RPN const &other);
    ~RPN();
};
