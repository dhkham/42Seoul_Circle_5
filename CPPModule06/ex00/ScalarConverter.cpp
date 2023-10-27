/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 19:14:14 by dkham             #+#    #+#             */
/*   Updated: 2023/10/27 21:28:47 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <limits>
#include <cmath>

void ScalarConverter::convert(const std::string &literal) {
    if (literal == "inf" || literal == "+inf" || literal == "-inf" || literal == "nan" || literal == "-inff") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;

        if (literal == "inf" || literal == "+inf") {
            std::cout << "float: inff" << std::endl;
            std::cout << "double: inf" << std::endl;
        } else if (literal == "-inf" || literal == "-inff") {
            std::cout << "float: -inff" << std::endl;
            std::cout << "double: -inf" << std::endl;
        } else if (literal == "nan") {
            std::cout << "float: nanf" << std::endl;
            std::cout << "double: nan" << std::endl;
        }
        return;  // Return here to exit the function
    } else {
        try {
            double doubleValue = convertToDouble(literal);

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
            if (fValue == floor(fValue) && !std::isnan(fValue) && !std::isinf(fValue) && fValue < 1e7 && fValue > -1e7) {
                std::cout << ".0";
            }
            std::cout << "f" << std::endl;


            // std::cout << "double: " << doubleValue;
            // if (doubleValue == floor(doubleValue) && !std::isnan(doubleValue) && !std::isinf(doubleValue)) {
            //     std::cout << ".0";
            // }
            // std::cout << std::endl;
            
            std::cout << "double: " << doubleValue;
            if (doubleValue == static_cast<int>(doubleValue) && !std::isnan(doubleValue) && !std::isinf(doubleValue)) {
                std::cout << ".0";
            }
            std::cout << std::endl;

        } catch (const std::exception &e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
}

char ScalarConverter::convertToChar(double value) {
    if (std::isnan(value) || std::isinf(value) || value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max())
        throw std::runtime_error("impossible");
    char c = static_cast<char>(value);
    if (!std::isprint(c))
        throw std::runtime_error("Non displayable");
    return c;
}

int ScalarConverter::convertToInt(double value) {
    if (std::isnan(value) || std::isinf(value) || value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
        throw std::runtime_error("impossible");
    return static_cast<int>(value);
}

float ScalarConverter::convertToFloat(double value) {
    if (value < std::numeric_limits<float>::lowest() || value > std::numeric_limits<float>::max())
        throw std::runtime_error("impossible");
    return static_cast<float>(value);
}

double ScalarConverter::convertToDouble(const std::string &literal) {
    if (literal == "inf" || literal == "+inf")
        return std::numeric_limits<double>::infinity();
    else if (literal == "-inf")
        return -std::numeric_limits<double>::infinity();
    else if (literal == "nan")
        return std::numeric_limits<double>::quiet_NaN();
    else
        return std::stod(literal);
}
