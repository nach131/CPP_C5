/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 02:07:58 by nmota-bu          #+#    #+#             */
/*   Updated: 2024/01/28 19:03:47 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <iostream>

class Convert
{
private:
	Convert();
	Convert(const Convert &);
	Convert &operator=(const Convert &);

public:
	~Convert();
	Convert(char, bool);
	Convert(int, bool);
	Convert(double, bool);
	Convert(float, bool);
};

#endif
