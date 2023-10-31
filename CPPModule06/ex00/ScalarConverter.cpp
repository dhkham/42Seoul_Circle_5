/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 19:14:14 by dkham             #+#    #+#             */
/*   Updated: 2023/10/31 20:56:48 by dkham            ###   ########.fr       */
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
        return;
    } else if (lit.length() == 1) {
        char cValue = static_cast<char>(lit[0]);
        if (std::isprint(cValue) && !std::isdigit(cValue)) { // if the char is printable and not a digit (e.g., 'a', 'b', 'c', etc.)
            std::cout << "char: '" << cValue << "'" << std::endl;
        } else {
            std::cout << "char: Non displayable" << std::endl;
        }
        std::cout << "int: impossible" << std::endl;
        std::cout << "float impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    } 
    else {
        try { // if stod throws an exception, it will be caught here
            double doubleValue = stringToDouble(lit); // Convert the lit to double first before converting to other types

            try {
                char cValue = doubleToChar(doubleValue);
                std::cout << "char: '" << cValue << "'" << std::endl;
            } catch (const std::exception &e) {
                std::cout << "char: " << e.what() << std::endl;
            }

            try {
                int iValue = doubleToInt(doubleValue);
                std::cout << "int: " << iValue << std::endl;
            } catch (const std::exception &e) {
                std::cout << "int: " << e.what() << std::endl;
            }

            try {
                float fValue = doubleToFloat(doubleValue);
                std::cout << "float: " << fValue;
                if (fValue == floor(fValue) && fValue < 1e7 && fValue > -1e7) {
                    std::cout << ".0";
                }
                std::cout << "f" << std::endl;
            } catch (const std::exception &e) {
                std::cout << "float: " << e.what() << std::endl;
            }

            // no try-catch for double because it will never throw an exception here:
            // if stod throws an exception, it will be caught above and print "impossible" for all types
            std::cout << "double: " << doubleValue;
            if (doubleValue == static_cast<int>(doubleValue)) {
                std::cout << ".0";
            }
            std::cout << std::endl;

        } catch (const std::exception &e) {
            std::cout << "char: " << "impossible" << std::endl;
            std::cout << "int: " << "impossible" << std::endl;
            std::cout << "float: " << "impossible" << std::endl;
            std::cout << "double: " << "impossible" << std::endl;
        }
    }
}

double ScalarConverter::stringToDouble(const std::string& s) {
    std::string cleanedString = s;

    // If the string ends with 'f' remove it.
    if (!cleanedString.empty() && (cleanedString[cleanedString.size() - 1] == 'f')) {
    cleanedString = cleanedString.substr(0, cleanedString.size() - 1); // substr(startIndex, length)
    }
    std::istringstream iss(cleanedString);
    double result;
    iss >> result;
    if (iss.fail() || !iss.eof()) {  
        throw std::runtime_error("Failed to convert string to double");
    }
    return result;
}

char ScalarConverter::doubleToChar(double value) {
    if (value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max()) // if the value is not in the range of char
        throw std::runtime_error("impossible");
    char c = static_cast<char>(value);
    if (!std::isprint(c))
        throw std::runtime_error("Non displayable");
    return c;
}

int ScalarConverter::doubleToInt(double value) {
    if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
        throw std::runtime_error("impossible");
    return static_cast<int>(value);
}

float ScalarConverter::doubleToFloat(double value) {
    if (value < -std::numeric_limits<float>::max() || value > std::numeric_limits<float>::max())
        throw std::runtime_error("impossible");
    return static_cast<float>(value);
}
