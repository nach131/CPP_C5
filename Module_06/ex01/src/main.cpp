
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

#include "Colors_ft.hpp"
#include "libft_p.hpp"
#include "Data.hpp"
#include <limits.h>

void print(Data &ptr)
{
	std::cout << "String: " << ptr.str << std::endl;
	std::cout << "Bool: " << ptr.flag << std::endl;
	std::cout << "Integer: " << ptr.num << std::endl;
	std::cout << "▁▁▁▁▁▁▁▁▁▁" << std::endl;
}

uintptr_t serialize(Data *ptr) { return reinterpret_cast<uintptr_t>(ptr); }

Data *deserialize(uintptr_t raw) { return reinterpret_cast<Data *>(raw); }

int main(void)
{
	printStringInCenter("Dynamic memory");
	{
		Data *data = new Data;
		data->str = "Dynamic Data";
		data->flag = true;
		data->num = 42;

		print(*data);

		std::cout << "Original ptr: " << data << std::endl;
		uintptr_t seri = serialize(data);

		std::cout << "Serialization: " << seri << std::endl;
		std::cout << "Desserializarion: " << deserialize(seri)->str << std::endl;
		std::cout << "Desserializarion: " << deserialize(seri)->flag << std::endl;
		std::cout << "Desserializarion: " << deserialize(seri)->num << std::endl;

		delete data;
	}
	printStringInCenter("Memory on the stack");
	{
		Data data;
		data.str = "Stack Data";
		data.flag = false;
		data.num = 4242;

		print(data);

		std::cout << "Original ptr: " << &data << std::endl;
		uintptr_t seri = serialize(&data);

		std::cout << "Serialization: " << seri << std::endl;
		std::cout << "Desserializarion: " << deserialize(seri)->str << std::endl;
		std::cout << "Desserializarion: " << deserialize(seri)->flag << std::endl;
		std::cout << "Desserializarion: " << deserialize(seri)->num << std::endl;
	}

	return 0;
}
