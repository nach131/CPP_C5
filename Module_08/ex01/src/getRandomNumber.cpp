/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getRandomNumber.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:48:05 by nmota-bu          #+#    #+#             */
/*   Updated: 2024/02/02 11:53:52 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <random>

int getRandomNumber(int start, int end)
{
	std::random_device rd;	// Obtén una semilla aleatoria del dispositivo
	std::mt19937 gen(rd()); // Usa el generador Mersenne Twister con la semilla aleatoria

	// Define la distribución uniforme entre start y n (ambos inclusive)
	std::uniform_int_distribution<> distribution(start, end);

	// Genera y devuelve un número aleatorio
	return distribution(gen);
}
