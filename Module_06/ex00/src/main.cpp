/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:22:20 by nmota-bu          #+#    #+#             */
/*   Updated: 2024/01/26 20:46:46 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors_ft.hpp"
#include "libft_p.hpp"

int err_argc(int n)
{
	system("clear");
	if (n > 1)
		std::cout << MAIN << "[Number to convert]" RESET << " ";
	else
		std::cout << ERROR << "[Number to convert]" RESET << " ";
	std::cout << ERROR << "[Name]" RESET << std::endl;
	return EXIT_FAILURE;
}

int main(int n, char **str)
{
	(void)str;
	if (n != 3)
		return err_argc(n);

	printStringInCenter(str[2]);
	{
	}
	return 0;
}
