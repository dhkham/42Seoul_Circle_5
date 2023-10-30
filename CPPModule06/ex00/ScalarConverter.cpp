/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 19:14:14 by dkham             #+#    #+#             */
/*   Updated: 2023/10/30 19:53:29 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <limits>
#include <cmath>

void ScalarConverter::convert(const std::string &lit) {
    if (lit == "inf" || lit == "+inf" || lit == "-inf" || lit == "inff" || lit == "+inff" || lit == "-inff" || lit == "nan" || lit == "nanf") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;

        if (lit == "inf" || lit == "+inf" || lit == "inff" || lit == "+inff") {
            std::cout << "float: inff" << std::endl;
            std::cout << "double: inf" << std::endl;
        } else if (lit == "-inf" || lit == "-inff" || lit == "-inf" || lit == "-inff") {
            std::cout << "float: -inff" << std::endl;
            std::cout << "double: -inf" << std::endl;
        } else if (lit == "nan" || lit == "nanf") {
            std::cout << "float: nanf" << std::endl;
            std::cout << "double: nan" << std::endl;
        }
        return;  // Return here to exit the function
    } else {
        try {
            double doubleValue = convertToDouble(lit); // Convert the lit to double first 

            try {
                char cValue = convertToChar(doubleValue);
                std::cout << "char: '" << cValue << "'" << std::endl;
            } catch (const std::exception &e) {
                std::cout << "char: " << e.what() << std::endl;
            }

            try {
                int iValue = convertToInt(doubleValue);
                std::cout << "int: " << iValue << std::endl;
            } catch (const std::exception &e) {
                std::cout << "int: " << e.what() << std::endl;
            }

            float fValue = convertToFloat(doubleValue);
            std::cout << "float: " << fValue;
            if (fValue == floor(fValue) && fValue < 1e7 && fValue > -1e7) {
                std::cout << ".0";
            }
            std::cout << "f" << std::endl;
            
            std::cout << "double: " << doubleValue;
            if (doubleValue == static_cast<int>(doubleValue)) {
                std::cout << ".0";
            }
            std::cout << std::endl;

        } catch (const std::exception &e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
}

char ScalarConverter::convertToChar(double value) {
    if (value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max()) // if the value is not in the range of char
        throw std::runtime_error("impossible");
    char c = static_cast<char>(value);
    if (!std::isprint(c))
        throw std::runtime_error("Non displayable");
    return c;
}

int ScalarConverter::convertToInt(double value) {
    if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
        throw std::runtime_error("impossible");
    return static_cast<int>(value);
}

float ScalarConverter::convertToFloat(double value) {
    if (value < std::numeric_limits<float>::lowest() || value > std::numeric_limits<float>::max())
        throw std::runtime_error("impossible");
    return static_cast<float>(value);
}

double ScalarConverter::convertToDouble(const std::string &lit) {
    return std::stod(lit);  // Convert the lit to double
}
