
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
#include <cstdlib>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main(void)
{
	printStringInCenter("Ptr");
	{

		Base One;

		Base *Son1 = One.generate();
		Base *Son2 = One.generate();
		Base *Son3 = One.generate();

		One.identify(Son1);
		One.identify(Son2);
		One.identify(Son3);

		delete Son1;
		delete Son2;
		delete Son3;
	}
	printStringInCenter("Ref");
	{

		Base One;

		A a;
		B b;
		C c;

		One.identify(a);
		One.identify(b);
		One.identify(c);
	}

	return 0;
}
