#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <cstdlib> // Para la función atoi

bool isOperator(const std::string &token)
{
	return token == "+" || token == "-" || token == "*" || token == "/";
}

int calculateRPN(const std::string &expression)
{
	std::istringstream iss(expression);
	std::string token;
	std::stack<int> stack;

	while (iss >> token)
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
		{
			stack.push(atoi(token.c_str()));
		}
	}

	return stack.top();
}

int main()
{
	std::string expression = "2 2 + 1 + 1 + 4 9 * +";
	int result = calculateRPN(expression);
	std::cout << "Resultado de la expresión RPN: " << result << std::endl;

	return 0;
}
