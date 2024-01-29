/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printStringInCenter.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:19:15 by nmota-bu          #+#    #+#             */
/*   Updated: 2024/01/29 21:42:17 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <sys/ioctl.h>
#include <unistd.h>
#include "ColorsFt.hpp"

int getTerminalWidth()
{
	struct winsize size;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
	return size.ws_col;
}

// Función para imprimir la cadena en el centro de la terminal
void printStringInCenter(const std::string &str)
{
	int terminalWidth = getTerminalWidth();

	// std::cout << terminalWidth << std::endl;
	// Calcular la posición para imprimir en el centro
	int padding = (terminalWidth - str.length()) / 2;

	// Imprimir espacios en blanco para centrar la cadena
	for (int i = 0; i < padding; ++i)
		std::cout << BLUE << "▁" << RESET;

	// Imprimir la cadena en el centro
	std::cout << MAIN << str << RESET;

	// Imprimir espacios en blanco después de la cadena hasta el final de la columna
	for (int i = padding + str.length(); i < terminalWidth; ++i)
		std::cout << BLUE << "▁" << RESET;

	std::cout << std::endl;
}

// int main()
// {
// 	std::string str = "[ 42 Barcelona ]";

// 	printStringInCenter(str);

// 	return 0;
// }
