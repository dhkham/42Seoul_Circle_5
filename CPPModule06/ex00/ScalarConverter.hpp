/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 19:13:56 by dkham             #+#    #+#             */
/*   Updated: 2023/10/30 21:03:21 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter {
public:
    static void convert(const std::string &literal);
private:
    ScalarConverter();                                       // Default constructor
    ScalarConverter(const ScalarConverter &);                // Copy constructor
    ScalarConverter &operator=(const ScalarConverter &);     // Copy assignment operator
    ~ScalarConverter();                                      // Destructor

    static char convertToChar(double value);
    static int convertToInt(double value);
    static float convertToFloat(double value);
    static double convertToDouble(const std::string &literal);
};

#endif

